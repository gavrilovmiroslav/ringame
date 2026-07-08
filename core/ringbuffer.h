//
// Created by mika on 7/7/26.
//

#ifndef RINGAME_RINGBUFFER_H
#define RINGAME_RINGBUFFER_H

#include <cassert>
#include <deque>
#include <iostream>
#include <typeinfo>

template<typename TElement>
class RingBuffer
{
public:
    RingBuffer() : m_Current{0}, m_Elements{}
    {}

    void Push(TElement element)
    {
#if defined(RG_DEBUG)
        std::cout << "Adding [" << element->Name() << "] to end of buffer." << std::endl;
#endif
        m_Elements.push_back(element);
    }

    void PushNext(TElement element)
    {
#if defined(RG_DEBUG)
        std::cout << "Adding [" << element->Name() << "] next in buffer." << std::endl;
#endif
        m_Elements.insert(m_Elements.begin() + m_Current + 1, element);
    }

    void Clear()
    {
        m_Elements.clear();
    }

    bool IsEmpty() const
    {
        return m_Elements.empty();
    }

    void Print()
    {
        int i = 0;
        for (auto& e : m_Elements)
        {
            if (i == m_Current)
                std::cout << "<" << e->Name() << "> ";
            else
                std::cout << "[" << e->Name() << "] ";

            i++;
        }
        std::cout << std::endl;
    }

    void Consume()
    {
#if defined(RG_DEBUG)
        std::cout << "BEFORE: ";
        Print();
#endif
        assert(!m_Elements.empty());
        m_Elements.erase(m_Elements.begin() + m_Current);
#if defined(RG_DEBUG)
        std::cout << "AFTER: ";
        Print();
#endif
    }

    TElement& Current()
    {
        return m_Elements[m_Current];
    }

    TElement& Back()
    {
        m_Current--;
        if (m_Current < 0) m_Current = m_Elements.size() - 1;
        return m_Elements[m_Current];
    }

    TElement& Next()
    {
        m_Current = (m_Current + 1) % m_Elements.size();
        return m_Elements[m_Current];
    }

private:
    int m_Current;
    std::deque<TElement> m_Elements;
};

#endif //RINGAME_RINGBUFFER_H
