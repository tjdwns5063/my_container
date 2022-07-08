#ifndef IS_INPUT_ITERATOR_HPP
# define IS_INPUT_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {
    template <typename T, typename C>
    struct is_category { static const bool value = false; };

    template <typename T>
    struct is_category<T, ft::input_iterator_tag> { static const bool value = true; };
    
    template <typename T>
    struct is_category<T, ft::forward_iterator_tag> { static const bool value = true; };

    template <typename T>
    struct is_category<T, ft::bidirectional_iterator_tag> { static const bool value = true; };

    template <typename T>
    struct is_category<T, ft::random_access_iterator_tag> { static const bool value = true; };
    
    template <typename T>
    struct is_category<T, std::input_iterator_tag> { static const bool value = true; };
    
    template <typename T>
    struct is_category<T, std::forward_iterator_tag> { static const bool value = true; };

    template <typename T>
    struct is_category<T, std::bidirectional_iterator_tag> { static const bool value = true; };

    template <typename T>
    struct is_category<T, std::random_access_iterator_tag> { static const bool value = true; };

    template <typename T>
    struct is_input_iterator: public is_category<T, typename T::iterator_category> {};
}

#endif