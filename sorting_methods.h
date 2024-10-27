#include <chrono>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

void fill_random(std::vector<int>& values, int max_value)
{
    std::srand(0);
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = std::rand() % max_value;
    }
}

void fill_incremental(std::vector<int>& values, int max_value)
{
    double section = max_value / static_cast<double>(values.size());
    double current = 0.0;
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = static_cast<int>(current);
        current += section;
    }
}

void fill_decremental(std::vector<int>& values, int max_value)
{
    double section = max_value / static_cast<double>(values.size());
    double current = 0.0;
    for (int i = values.size() - 1; i >= 0; --i) {
        values.at(i) = static_cast<int>(current);
        current += section;
    }
}

// Time complexity: O(N^2)
void selection_sort(std::vector<int>& data)
{
    for (int i = 0; i < data.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < data.size(); j++) {
            if (data.at(j) < data.at(min_index)) {
                min_index = j;
            }
        }
        std::swap(data.at(i), data.at(min_index));
    }
}

void insertion_sort(std::vector<int>& data)
{
    for (int i = 1; i < data.size(); i++)
    {
        for (int j = 0; j < data.size(); j++)
        {
            if (j < i && data[j] > data[i])
            {
                std::swap(data.at(j), data.at(i));
            }
        }
    }
}

void bubble_sort(std::vector<int>& data)
{
    bool not_sorted = true;

    while (not_sorted)
    {
        not_sorted = false;

        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] < data[i - 1])
            {
                std::swap(data.at(i), data.at(i - 1));
                not_sorted = true;
            }
        }
    }
}

int divider(std::vector<int>& values, int start, int end) {
    int index = start + std::rand()% (end - start + 1);
    int divider = values.at(index);

    std::swap(values.at(index), values.at(end));
    int i = start - 1;
    for(int j = start; j < end; j++) {
        if (values.at(j) < divider) {
        i++;
        std::swap(values.at(i), values.at(j));
        }
    }
    std::swap(values.at(i + 1), values.at(end));
    return i + 1;
}

void quick_sort(std::vector<int>& values, int start, int end) {
    if (start < end) {
    int middle = divider(values, start, end);
    quick_sort(values, start, middle - 1);
    quick_sort(values, middle + 1, end);
    }
}

void counting_sort(std::vector<int>& values, int max_value) {
    std::vector<int> counts(max_value + 1, 0);

    for(int i = 0; i < values.size(); i++) {
        counts[values.at(i)] ++;
    }

    int index = 0;
    for(int i = 0; i <= max_value; ++i) {
        for(int j = 0; j < counts[i]; ++j) {
            values.at(index) = i;
            index++;
        }
    }
}

void merge_sort(std::vector<int>& data, std::vector<int>& scratch, int start, int end)
{
    // When only one item, the array is sorted
    if (start == end)
        return;

    // Get midpoint to split in two halves
    int midpoint = (start + end)/2;

    // Call recursively to sort the two halves
    merge_sort(data, scratch, start, midpoint);
    merge_sort(data, scratch, midpoint + 1, end);

    // Merge two halves
    int left_index = start;
    int right_index = midpoint + 1;
    int scratch_index = left_index;

    while ((left_index <= midpoint) && (right_index <= end))
    {
        if (data[left_index] <= data[right_index])
        {
            scratch[scratch_index] = data[left_index];
            left_index = left_index + 1;
        }
        else
        {
            scratch[scratch_index] = data[right_index];
            right_index = right_index + 1;
        }

        scratch_index++;
    }

    while (left_index <= midpoint)
    {
        scratch[scratch_index] = data[left_index];
        scratch_index++;
        left_index++;
    }
    while (right_index <= end)
    {
        scratch[scratch_index] = data[right_index];
        scratch_index++;
        right_index++;
    }

    // Copy values back to original array
    for (int i = start; i <= end; i++)
    {
        data[i] = scratch[i];
    }
}

void print_vector(const std::vector<int> data) {
    for (int elem : data) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}