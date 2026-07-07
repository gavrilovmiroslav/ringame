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
        std::cout << "Adding [" << element->Name() << "] to end of buffer." << std::endl;
        m_Elements.push_back(element);
    }

    void PushNext(TElement element)
    {
        std::cout << "Adding [" << element->Name() << "] next in buffer." << std::endl;
        m_Elements.insert(m_Elements.begin() + m_Current + 1, element);
    }

    bool IsEmpty() const
    {
        return m_Elements.empty();
    }

    void Consume()
    {
        std::cout << "BEFORE: ";
        for (auto& e : m_Elements)
        {
            std::cout << "[" << e->Name() << "] ";
        }
        std::cout << std::endl;
        assert(!m_Elements.empty());
        m_Elements.erase(m_Elements.begin() + m_Current);
        std::cout << "AFTER: ";
        for (auto& e : m_Elements)
        {
            std::cout << "[" << e->Name() << "] ";
        }
        std::cout << std::endl;
    }

    TElement& Current()
    {
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
