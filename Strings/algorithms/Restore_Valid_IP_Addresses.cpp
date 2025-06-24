/**============================================================================
Name        : Restore_Valid_IP_Addresses.cpp
Created on  : 14.02.2025
Author      : Andrei Tokmakov
Version     : 1.0
Copyright   : Your copyright notice
Description :
============================================================================**/

#include "../common.h"
#include "../StringAlgorithms.h"

#include <queue>

/**
 93. Restore IP Addresses

A valid IP address consists of exactly four integers separated by single dots.
 Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses,
 but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid
 IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s.
 You may return the valid IP addresses in any order

 https://leetcode.com/problems/restore-ip-addresses/description/.
 **/

namespace
{
    using namespace StringAlgorithms;

    struct IP: std::array<uint8_t, 4> {};

    struct Ctx
    {
        int8_t from { 0 };
        IP ip {};
        uint8_t octet { 0 };
    };

    std::ostream& operator<<(std::ostream& stream, const IP& ip)
    {
        return stream << static_cast<int>(ip[0]) << '.'
                      << static_cast<int>(ip[1]) << '.'
                      << static_cast<int>(ip[2]) << '.'
                      << static_cast<int>(ip[3]);
    }

    std::ostream& operator<<(std::ostream& stream, const Ctx& ctx)
    {
        return stream << "Ctx ( from: " << static_cast<int>(ctx.from)
            << ", octet: " << static_cast<int>(ctx.octet)
            << ", ip: " << ctx.ip << " )";
    }

    std::queue<Ctx> ctxQueue;

    void tryGetOctet(const std::string& ipStr,
                     Ctx ctx)
    {
        for (uint8_t pos = ctx.from + 1; pos <= ctx.from + 3 && pos <= ipStr.size() && ctx.octet < 4; ++pos)
        {
            if (std::errc() == std::from_chars(ipStr.data() + ctx.from , ipStr.data() + pos, ctx.ip[ctx.octet]).ec)
            {
                const Ctx& tmp = ctxQueue.emplace(pos, ctx.ip, ctx.octet + 1);
                if (pos == ipStr.size() && 3 == ctx.octet) {
                    std::cout << tmp.ip << std::endl;
                }
            }
        }
    }
}

void StringAlgorithms::Restore_Valid_IP_Addresses()
{
    const std::string ipStr { "101023" };

    ctxQueue.emplace();
    while (!ctxQueue.empty()) {
        Ctx ctx = ctxQueue.front();
        ctxQueue.pop();
        tryGetOctet(ipStr, ctx);
    }
}