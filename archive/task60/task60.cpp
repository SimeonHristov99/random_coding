#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <map>

class RateLimiter
{
private:
    int m_expire;
    std::map<int, int> users;

public:
    RateLimiter(int expire)
    {
        m_expire = expire;
    }

    bool limit(int uid, int timestamp)
    {
        std::map<int, int>::iterator it = users.find(uid);

        if (it == users.end())
        {
            users.insert({uid, timestamp});
            return false;
        }

        if (timestamp - it->second < m_expire)
        {
            return true;
        }

        it->second = timestamp;
        return false;
    }
};

TEST_CASE("Example 1")
{
    RateLimiter rl(5);

    CHECK_FALSE(rl.limit(0, 10));
    CHECK_FALSE(rl.limit(0, 15));
    CHECK(rl.limit(0, 16));
    CHECK_FALSE(rl.limit(1, 17));
}

TEST_CASE("Example 2")
{
    RateLimiter rl(0);
    CHECK_FALSE(rl.limit(0, 1));
    CHECK_FALSE(rl.limit(0, 1));
    CHECK_FALSE(rl.limit(0, 2));
    CHECK_FALSE(rl.limit(1, 3));
}

TEST_CASE("Example 3")
{
    RateLimiter rl(5);
    CHECK_FALSE(rl.limit(0, 10));
    CHECK(rl.limit(0, 13));
    CHECK_FALSE(rl.limit(0, 16));
}