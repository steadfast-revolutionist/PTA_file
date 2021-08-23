#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Num {
    long long head = 0;
    long long first;
    long long last;
};

Num operator * (const Num& num1, const Num& num2) {
    return {0, num1.first * num2.first, num2.last * num1.last};
}

Num operator / (const Num& num1, const Num& num2) {
    return {0, num1.first * num2.last, num1.last * num2.first};
}

Num operator + (const Num& num1, const Num& num2) {
    return {0, num1.first * num2.last + num1.last * num2.first, num1.last * num2.last};
}

Num operator - (const Num& num1, const Num& num2) {
    return {0, num1.first * num2.last - num1.last * num2.first, num1.last * num2.last};
}

int print(const Num &num);
Num &set(Num &);
void measure(long long &, long long &);

int main()
{
    Num num1, num2;

    scanf("%lld/%lld %lld/%lld", &num1.first,
          &num1.last, &num2.first, &num2.last);

    Num sum = num1 + num2;
    Num sub = num1 - num2;
    Num mult = num1 * num2;
    Num over = num1 / num2;

    print(set(num1)); printf(" + "); print(set(num2)); printf(" = "); print(set(sum)); puts("");
    print(set(num1)); printf(" - "); print(set(num2)); printf(" = "); print(set(sub)); puts("");
    print(set(num1)); printf(" * "); print(set(num2)); printf(" = "); print(set(mult)); puts("");
    print(set(num1)); printf(" / "); print(set(num2)); printf(" = "); print(set(over)); puts("");

    return 0;
}

int print(const Num& num) {
    if (num.last == 0) {
        printf("Inf");
        return 0;
    }
    if (num.first == 0) {
        if (num.head < 0) {
            printf("(%lld)", num.head);
        } else {
            printf("%lld", num.head);
        }
        return 0;
    }

    if (num.head != 0) {
        if (num.head < 0) {
            printf("(%lld %lld/%lld)", num.head, num.first, num.last);
        } else {
            printf("%lld %lld/%lld", num.head, num.first, num.last);
        }
    } else {
        if (num.first < 0) {
            printf("(%lld/%lld)", num.first, num.last);
        } else {
            printf("%lld/%lld", num.first, num.last);
        }
    }

    return 0;
}

Num &set(Num& num) {
    if (num.last != 0 && num.first != 0) {
        num.head = num.first / num.last;
        num.first -= num.head * num.last;
        if (num.head == 0 && num.last < 0) {
            num.last = 0 - num.last;
            num.first = 0 - num.first;
        } else if (num.head != 0) {
            num.last = abs(num.last);
            num.first = abs(num.first);
        }
        measure(num.first, num.last);
    }

    return num;
}

void measure(long long& num1, long long& num2) {
    long long a = abs(num1), b = abs(num2), c = abs(num2);

    while (a % b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    num1 /= c;
    num2 /= c;
}
