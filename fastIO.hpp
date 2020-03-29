#ifndef __FAST_IO_HPP__
#define __FAST_IO_HPP__

#include <iostream>
#include <cstdio>
using namespace std;

namespace FastIO {
    typedef long long lint;
    inline void writeInt(lint x) {
        static int sta[40];
        int top = 0;
        do {
            sta[top++] = x % 10;
            x /= 10;
        } while (x);
        while (top) putchar(sta[--top] + 48);
    }

    inline void writeString(string & s) {
        for(string::iterator b = s.begin(); b != s.end(); ++b) putchar(*b);
    }

    lint readInt() {
        lint x = 0, w = 1;
        char ch = 0;
        while (ch < '0' || ch > '9') {
            if (ch == '-') w = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + (ch - '0');
            ch = getchar();
        }
        return x * w;
    }

    class EndLine {} endline;

    class IO {
    public:
        IO &operator<<(EndLine & e) {
            putchar('\n');
            return *this;
        }
        IO &operator<<(int &x) {
            writeInt(static_cast<lint>(x));
            return *this;
        }

        IO &operator<<(lint &x) {
            writeInt(x);
            return *this;
        }
        IO &operator<<(char & c) {
            putchar(c);
            return *this;
        }
        IO &operator<<(string & s) {
            writeString(s);
            return *this;
        }
        IO &operator>>(int & x) {
            x = readInt();
            return *this;
        }
        IO &operator>>(lint & x) {
            x = readInt();
            return *this;
        }
        IO &operator>>(char & c) {
            c = getchar();
            return *this;
        }
        IO &operator>>(string & s) {
            char ch = '*';
            while(ch != '\n' && ch != ' ') {
                ch = getchar();
                s += ch;
            }
            return * this;
        }
    } io;
}
/**
 * You can just use fast io like cin and cout to against the fvcking TLE!
 * here is an example:
 * int x; double y; string z;
 * io >> x >> y >> z;
 * io << x << y << z << endline;
 * (endline is like std's endl but it's just create next line, won't flush the buffer.)
 */

#endif