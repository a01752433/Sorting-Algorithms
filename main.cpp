#include"sorting_methods.h"
int main()
{
    std::vector<int> v(10000000);

    // fill_random(v, 1000);
    // fill_incremental(v, 1000);
    fill_decremental(v, 1000);
    std::cout << "Is sorted: " << std::is_sorted(v.begin(), v.end()) << "\n";
    // print_vector(v);

    auto start = std::chrono::high_resolution_clock::now();
    counting_sort(v, *std::max_element(v.begin(), v.end()));
    // std::sort(v.begin(), v.end());
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop - start);
    double total_time = duration.count() / 1'000'000.0;

    std::cout << "Is sorted: " << std::is_sorted(v.begin(), v.end()) << "\n";
    // print_vector(v);
    std::cout << "Time: " << total_time << " seconds\n";
    return 0;
}