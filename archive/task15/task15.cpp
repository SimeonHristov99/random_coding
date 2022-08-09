#include <iostream>
#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
    if (snail_map[0].size() == 0)
    {
        return {};
    }

    std::vector<int> result = {};

    int row_idx = 0;
    int col_idx = 0;

    int row_limit = snail_map.size();
    int col_limit = row_limit;

    while (row_limit > 0 && col_limit > 0)
    {
        for (int i = 0; i < col_limit; ++i)
        {
            result.push_back(snail_map[row_idx][col_idx]);
            ++col_idx;

            if (row_idx == row_limit && col_idx == col_limit)
            {
                return result;
            }
        }

        --col_idx;
        --row_limit;
        for (int i = 0; i < row_limit; ++i)
        {
            ++row_idx;
            result.push_back(snail_map[row_idx][col_idx]);
        }

        --col_limit;
        for (int i = 0; i < col_limit; ++i)
        {
            --col_idx;
            result.push_back(snail_map[row_idx][col_idx]);
        }

        --col_limit;
        --row_limit;
        for (int i = 0; i < row_limit; ++i)
        {
            --row_idx;
            result.push_back(snail_map[row_idx][col_idx]);
        }

        ++col_idx;
    }

    return result;
}

int main()
{
    std::vector<std::vector<int>> snail_map = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> result = snail(snail_map);

    for (const int x : result)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    snail_map = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    result = snail(snail_map);

    for (const int x : result)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    snail_map = {{}};
    result = snail(snail_map);

    for (const int x : result)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    snail_map = {{1}};
    result = snail(snail_map);

    for (const int x : result)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    snail_map = {{1, 2, 3, 1}, {4, 5, 6, 4}, {7, 8, 9, 7}, {7, 8, 9, 7}};
    result = snail(snail_map);

    for (const int x : result)
    {
        std::cout << x << ' '; // {1,2,3,1,4,7,7,9,8,7,7,4,5,6,9,8}
    }
    std::cout << '\n';

    snail_map = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    result = snail(snail_map);

    for (const int x : result)
    {
        std::cout << x << ' '; // {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}
    }
    std::cout << '\n';

    snail_map = {
        {750, 765, 923, 876, 132, 680, 497, 200, 251, 690, 895, 3, 582, 932},
        {787, 437, 583, 679, 581, 549, 266, 99, 312, 830, 217, 251, 265, 410},
        {179, 299, 783, 493, 643, 281, 730, 188, 574, 75, 304, 441, 36, 263},
        {659, 772, 368, 437, 702, 426, 877, 160, 430, 413, 922, 781, 884, 13},
        {174, 145, 32, 224, 572, 696, 629, 724, 45, 332, 140, 811, 190, 41},
        {77, 809, 622, 902, 462, 2, 794, 480, 549, 326, 773, 674, 71, 159},
        {883, 603, 305, 608, 184, 57, 830, 246, 834, 145, 843, 606, 139, 747},
        {448, 327, 544, 684, 617, 307, 948, 217, 931, 931, 926, 28, 578, 517},
        {40, 564, 623, 671, 861, 970, 74, 170, 424, 826, 893, 18, 84, 274},
        {703, 378, 240, 964, 221, 847, 67, 180, 130, 443, 220, 938, 68, 249},
        {618, 305, 682, 286, 584, 385, 571, 15, 974, 255, 125, 821, 421, 823},
        {681, 877, 339, 279, 44, 313, 624, 511, 419, 348, 885, 415, 979, 67},
        {117, 969, 340, 618, 853, 67, 458, 273, 637, 938, 783, 159, 717, 440},
        {482, 816, 873, 492, 427, 583, 834, 562, 433, 51, 39, 877, 351, 925},
    };
    result = snail(snail_map);

    for (const int x : result)
    {
        std::cout << x << ' ';
        /*
        { 750, 765, 923, 876, 132, 680, 497, 200, 251, 690, 895, 3, 582, 932, 410, 
        263, 13, 41, 159, 747, 517, 274, 249, 823, 67, 440, 925, 351, 877, 39, 51, 
        433, 562, 834, 583, 427, 492, 873, 816, 482, 117, 681, 618, 703, 40, 448, 
        883, 77, 174, 659, 179, 787, 437, 583, 679, 581, 549, 266, 99, 312, 830, 
        217, 251, 265, 36, 884, 190, 71, 139, 578, 84, 68, 421, 979, 717, 159, 
        783, 938, 637, 273, 458, 67, 853, 618, 340, 969, 877, 305, 378, 564, 327,
        603, 809, 145, 772, 299, 783, 493, 643, 281, 730, 188, 574, 75, 304, 441, 
        781, 811, 674, 606, 28, 18, 938, 821, 415, 885, 348, 419, 511, 624, 313, 
        44, 279, 339, 682, 240, 623, 544, 305, 622, 32, 368, 437, 702, 426, 877, 
        160, 430, 413, 922, 140, 773, 843, 926, 893, 220, 125, 255, 974, 15, 571, 
        385, 584, 286, 964, 671, 684, 608, 902, 224, 572, 696, 629, 724, 45, 332, 
        326, 145, 931, 826, 443, 130, 180, 67, 847, 221, 861, 617, 184, 462, 2, 
        794, 480, 549, 834, 931, 424, 170, 74, 970, 307, 57, 830, 246, 217, 948 }
        */
    }
    std::cout << '\n';

    return 0;
}