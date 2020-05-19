#pragma once

#include "buffer_exceptions.h"

template <class T>
class circular_buffer {
public:

    circular_buffer(unsigned capacity = 255)
    : capacity_(capacity)
    {
        if (capacity == 0)
            throw buffer_underflow_exception();
        start_ = new buffer_element();
        end_ = nullptr;
        buffer_element* cur = start_;
        for (int i = 1; i < capacity; i++) {
            cur->next = new buffer_element();
            cur->next->prev = cur;
            cur = cur->next;
        }
        cur->next = start_;
        start_->prev = cur;
    }

    circular_buffer(const circular_buffer<T>& other)
    : capacity_(other.capacity_)
    {
        start_ = new buffer_element();

        buffer_element* cur = start_;
        buffer_element* other_cur = other.start_;

        bool content_end = other.start_ == nullptr;
        for (int i = 0; i < capacity_; i++) {
            if (!content_end)
                cur->value = other_cur->value;

            if (other_cur == other.end_) {
                end_ = cur;
                content_end = true;
            }

            cur->next = new buffer_element();
            cur->next->prev = cur;

            cur = cur->next;
            other_cur = other_cur->next;
        }
    }

    ~circular_buffer() {
        buffer_element* cur = start_->next;
        while (cur != start_) {
            buffer_element* next = cur->next;
            delete cur;
            cur = next;
        }
        delete start_;
    }

    void push_back(T value) {
        if (end_ == nullptr)
            end_ = start_;
        else if (end_->next == start_)
            start_ = start_->next;
        else
            end_ = end_->next;
        end_->value = value;
    }

    T pop_back() {
        if (end_ == nullptr)
            throw buffer_underflow_exception();

        T value = end_->value;

        if (end_ == start_)
            end_ = nullptr;
        else
            end_ = end_->prev;

        return value;
    }

    void push_front(T value) {
        if (end_ == nullptr) {
            end_ = start_;
            start_->next = end_;
            end_->prev = start_;
        }
        else if (start_->prev == end_)
            end_ = end_->prev;
        start_->prev->value = value;
        start_ = start_->prev;
    }

    T pop_front() {
        T value = start_->value;

        if (end_ == nullptr)
            throw buffer_underflow_exception();
        if (end_ == start_)
            end_ = nullptr;
        start_ = start_->next;
        return value;
    }

    T& front() {
        return start_->value;
    }

    T& back() {
        return end_->value;
    }

    T& operator [] (int idx) const {
        if (idx > capacity_ || end_ == nullptr)
            throw index_out_of_bounds_exception();

        buffer_element* cur = start_;
        for (int i = 0; i < idx; i++) {
            if (cur == end_)
                throw index_out_of_bounds_exception();
            cur = cur->next;
        }

        return cur->value;
    };

private:
    unsigned capacity_;

    struct buffer_element {
        buffer_element* prev;
        buffer_element* next;
        T value;
    };

    buffer_element* start_;
    buffer_element* end_;
};
