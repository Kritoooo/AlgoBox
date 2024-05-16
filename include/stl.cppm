module;

#include <algorithm>
#include <atomic>
#include <bit>
#include <cassert>
#include <charconv>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <experimental/source_location>
#include <filesystem>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <optional>
#include <random>
#include <set>
#include <shared_mutex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <condition_variable>
#include <mutex>
#include <variant>
#include <queue>

export module stl;

export namespace std {

    using std::shared_ptr;
    using std::make_shared;
    using std::unique_ptr;
    using std::make_unique;


    using std::experimental::source_location;
// using std::stringstream;
    using std::forward;
    using std::move;
    using std::exchange;
    using std::swap;

    using std::max;
    using std::min;

    using std::to_string;
    using std::from_chars;
    using std::errc;

    using std::stoi;
    using std::stol;
    using std::stoll;
    using std::strtol;
    using std::strtof;
    using std::strtod;

    using std::bit_cast;
    using std::memcpy;
    using std::strcmp;
    using std::memset;
    using std::memcmp;
    using std::strlen;

    using std::time;
    using std::printf;

    using std::is_same;
    using std::fill;
    using std::lower_bound;
    using std::upper_bound;

    using std::condition_variable;
    using std::condition_variable_any;
    using std::lock_guard;
    using std::memory_order;
    using std::memory_order_acq_rel;
    using std::memory_order_acquire;
    using std::memory_order_consume;
    using std::memory_order_relaxed;
    using std::memory_order_release;
    using std::memory_order_seq_cst;
    using std::mutex;
    using std::shared_lock;
    using std::shared_mutex;
    using std::unique_lock;
    using std::scoped_lock;

    using std::defer_lock;
    using std::adopt_lock;
    using std::try_to_lock;

    using std::binary_search;
    using std::fabs;
    using std::fill_n;
    using std::find;
    using std::floor;
    using std::ceil;
    using std::fmod;
    using std::forward_list;
    using std::isalnum;
    using std::isalpha;
    using std::isinf;
    using std::isnan;
    using std::log2;
    using std::make_heap;
    using std::nearbyint;
    using std::pop_heap;
    using std::pow;
    using std::remove_if;
    using std::reverse;
    using std::sort;
    using std::unique;
    using std::reduce;
    using std::accumulate;
    using std::sqrt;
    using std::transform;
    using std::copy_n;

    namespace ranges {

        using std::ranges::for_each;
        using std::ranges::equal;

    }

    using std::decay_t;
    using std::function;
    using std::numeric_limits;

    namespace chrono {
        using std::chrono::duration;
        using std::chrono::microseconds;
        using std::chrono::milliseconds;
        using std::chrono::nanoseconds;
        using std::chrono::seconds;
        using std::chrono::system_clock;

        using std::chrono::operator>;
        using std::chrono::operator>=;
        using std::chrono::operator<;
        using std::chrono::operator<=;
        using std::chrono::operator==;

        using std::chrono::operator+;
        using std::chrono::operator-;

        using std::chrono::minutes;
        using std::chrono::weeks;
        using std::chrono::years;

        using std::chrono::steady_clock;
        using std::chrono::time_point;
    } // namespace chrono

    using std::cout;
    using std::cerr;
    using std::endl;

    using std::ostream;
    using std::ofstream;
    using std::ifstream;
    using std::ios;

    using std::align;

    using std::ptrdiff_t;

    using std::static_pointer_cast;
    using std::dynamic_pointer_cast;

    namespace filesystem {
    using std::filesystem::canonical;
    using std::filesystem::copy;
    using std::filesystem::exists;
    using std::filesystem::file_size;
    using std::filesystem::path;
    using std::filesystem::remove;
    using std::filesystem::remove_all;
    }

    using std::iota;
    using std::mt19937;
    using std::random_device;
    using std::uniform_real_distribution;

    using std::exception;
    using std::unordered_set;

    using std::back_inserter;
    using std::hash;

    using std::string_view;
    using std::streamsize;

    using std::variant;
    using std::variant_size_v;
    using std::holds_alternative;
    using std::get;
    using std::visit;

    using std::is_integral_v;
    using std::is_floating_point_v;
    using std::common_type_t;
    using std::underlying_type_t;

    using std::function;
    using std::monostate;
    using std::thread;

    using std::is_same_v;
    using std::priority_queue;

    using std::begin;
    using std::end;

    using std::time_t;
    using std::asctime;
    using std::localtime;
} // namespace std