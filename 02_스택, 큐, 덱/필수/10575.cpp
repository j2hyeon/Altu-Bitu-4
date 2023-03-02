#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    string a, b, max, min;
    cin >> a >> b;

    // 문자열의 순서를 역순으로
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    max = (a.size() >= b.size() ? a : b); // a와 b중 큰 사이즈의 문자열을  max로 초기화
    min = (a.size() < b.size() ? a : b);  // a와 b중 작은 사이즈의 문자열을 min으로 초기화

    stack<int> stack; // int를 담는 stack선언
    int carry = 0;    // 자릿수를 더하는 변수(1이면 존재, 0이면 존재x)

    for (int i = 0; i < max.length(); i++) // max
    {
        int sum; // 각 자릿수의 합을 더해줄 변수
        // 문자열은 min과 max의 아스키코드를 담기에 '0'을 두 번 빼줘야함
        if (i < min.length())
        {
            sum = max[i] + min[i] - '0' - '0';
        }
        else
        { // max의 문자열만 담기에 '0'을 한 번 빼줘야함
            sum = max[i] - '0';
        }

        if (carry == 1) // 올림수가 존재했다면
        {
            sum++;     // sum에 1 더하여 올림처리
            carry = 0; // carry는 초기화
        }

        if (sum >= 10)
        {              // 합이 10이 넘어갈 떄 올림처리
            sum %= 10; // 나머지수가 sum으로 초기화
            carry = 1; // 다음 자릿수에 올림 존재
        }

        stack.push(sum); // sum을 stack에 넣어주기
    }

    // 최종 수의 합이 10이 넘어갈 때 최종으로 1을 push
    if (carry == 1)
    {
        stack.push(1);
    }

    // empty할때까지 top을 pop
    while (!stack.empty())
    {
        cout << stack.top(); // stack의 top을 출력 후
        stack.pop();         // 제거
    }
}
