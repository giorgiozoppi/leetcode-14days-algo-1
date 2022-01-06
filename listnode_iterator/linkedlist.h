
#include <memory>
/**
 * Problem Statement:
 * Implement a single linkedlist class in a way that it can supported by
 * STL algorithm count_if. Please do not use smart pointers;
 */
template <bool Const, typename T> class list_iterator;

template<typename T> class linked_list {
   public:
   struct list_node {
            T data;
            list_node* next;
    };
    private:
    list_node* tail{nullptr};
    list_node* head{nullptr};
    public:
    using iterator = list_iterator<false, T>;
    using const_iterator = list_iterator<true, T>;
    using iterator_category = std::forward_iterator_tag;
    
    linked_list(){}
    linked_list(const T& data) {
        list_node* v = new list_node();
        head = v;
        tail = v;
        v->data = data;
    }
    iterator begin() {
        return iterator(head);
    }
    iterator end() {
        return iterator(nullptr);
    }
    void append(const T& data) {
        list_node* v = new list_node();
        v->data = data;
        if (head == nullptr) {
            head = v;
            tail = v;
        } else {
            tail->next = v;
        }
    }
    ~linked_list(){
        for (auto headPtr = head; headPtr != nullptr; ) {
            auto tmp{headPtr->next};
            delete headPtr;
            headPtr = tmp;
        }
    }
};

template <bool Const, typename T> class list_iterator {
    friend class linked_list<T>;
    friend class list_iterator<!Const, T>;
    // handy alias for the node defined on the list
    using list_node_v = typename linked_list<T>::list_node;
    using node_ptr = std::conditional_t<Const, const list_node_v*, list_node_v*>;
    node_ptr ptr_;
    explicit list_iterator(node_ptr p): ptr_(p){}
    public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    
    using pointer = std::conditional_t<Const, const T*, T*>;
    // here i  assign to node_ptr at compile time if we've one behaviour or nor.
    using reference = std::conditional_t<Const, const T&, T&>;
    
    reference operator*() const { return ptr_->data; }
    auto& operator++() {
        ptr_ = ptr_->next;
        return *this;
    }
    auto operator++(int) {
        auto result = *this;
        ++*this;
        return result;
    }
    bool operator==(const list_iterator<Const,T>& rhs) const {
        return ptr_ == rhs.ptr_;
    }
    bool operator!=(const list_iterator<Const,T>& rhs) const {
        return ptr_ == rhs.ptr_;
    }
    operator list_iterator<true, T>() const {
        return list_iterator<true, T>{ptr_};
    }
};
