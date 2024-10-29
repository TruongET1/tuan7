#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm> // Ð? s? d?ng std::sort

int main() {
    // Khai báo d? li?u dân s?
    std::map<int, int> populationData = {
        {1920, 19}, {1921, 77}, {1922, 40}, {1923, 90}, {1924, 2},
        {1925, 25}, {1926, 54}, {1927, 17}, {1928, 79}, {1929, 6},
        {1930, 44}, {1931, 24}, {1932, 14}, {1933, 4}, {1934, 95},
        {1935, 47}, {1936, 66}, {1937, 48}, {1938, 23}, {1939, 98},
        {1940, 15}, {1941, 86}, {1942, 25}, {1943, 50}, {1944, 9},
        {1945, 29}, {1946, 64}, {1947, 3}, {1948, 67}, {1949, 4},
        {1950, 90}, {1951, 81}, {1952, 74}, {1953, 34}, {1954, 98},
        {1955, 13}, {1956, 87}, {1957, 96}, {1958, 56}, {1959, 90},
        {1960, 49}, {1961, 85}, {1962, 94}, {1963, 66}, {1964, 19},
        {1965, 95}, {1966, 47}, {1967, 42}, {1968, 65}, {1969, 87},
        {1970, 11}
    };

    // T?m s? lý?ng sinh ra l?n nh?t và nh? nh?t
    int maxBirths = std::numeric_limits<int>::min();
    int minBirths = std::numeric_limits<int>::max();

    for (const auto& entry : populationData) {
        if (entry.second > maxBirths) {
            maxBirths = entry.second;
        }
        if (entry.second < minBirths) {
            minBirths = entry.second;
        }
    }

    // T?m các nãm týõng ?ng v?i s? lý?ng sinh ra l?n nh?t và nh? nh?t
    std::vector<int> yearsMax;
    std::vector<int> yearsMin;

    for (const auto& entry : populationData) {
        if (entry.second == maxBirths) {
            yearsMax.push_back(entry.first);
        }
        if (entry.second == minBirths) {
            yearsMin.push_back(entry.first);
        }
    }

    // S?p x?p các nãm
    std::sort(yearsMax.begin(), yearsMax.end());
    std::sort(yearsMin.begin(), yearsMin.end());

    // T?m các nãm có cùng s? lý?ng ngý?i sinh ra
    std::unordered_map<int, std::vector<int>> birthYearsMap;
    for (const auto& entry : populationData) {
        birthYearsMap[entry.second].push_back(entry.first);
    }

    // In k?t qu?
    std::cout << "S? lý?ng ngý?i sinh ra l?n nh?t: " << maxBirths << " vào các nãm: ";
    for (int year : yearsMax) {
        std::cout << year << " ";
    }
    std::cout << std::endl;

    std::cout << "S? lý?ng ngý?i sinh ra nh? nh?t: " << minBirths << " vào các nãm: ";
    for (int year : yearsMin) {
        std::cout << year << " ";
    }
    std::cout << std::endl;

    // In ra các nãm có cùng s? lý?ng ngý?i sinh ra
    std::cout << "Các nãm có cùng s? lý?ng ngý?i sinh ra:" << std::endl;
    for (const auto& entry : birthYearsMap) {
        if (entry.second.size() > 1) { // Ch? in ra n?u có hõn 1 nãm
            std::cout << "S? ngý?i sinh ra: " << entry.first << " vào các nãm: ";
            for (int year : entry.second) {
                std::cout << year << " ";
            }

            std::cout << std::endl;
        }
    }

    return 0;
}