作者：牛客89号
链接：https://www.nowcoder.com/discuss/414
来源：牛客网

不算太难的题，数1-n之间，数字1出现的次数。
我们把n拆开:
(before) d (after)
d是我们要考虑的位，before是前面若干个高位， after是后面若干个低位。
无论d等于多少，前面若干位总是可以从0 变化到(before - 1), 这能包含before * w个1， w实际上是after的位数决定的，例如after有两位，后面可以从00变为99，所以可以乘以100。

特殊情况：
d == 1， 那么当高位变到before的时候 后面可以从0变化到(after + 1)，所以答案要加上(after + 1)
d > 1， 可以和之前统一的考虑，高位可以从0变化到before，而不用考虑after。
主要是细节，代码非常短。

#include <cstdio>
#include <cstring>
using namespace std;
 
int main() {
int n,answer  = 0;
    scanf("%d",&n);
    for (int w = 1, after = 0;n; w *= 10) {
        int before = n / 10;
        if (n % 10 == 1) {
            answer += after + 1;
        }
        after += n % 10 * w;
        answer += (before + ((n % 10 > 1)?1:0)) * w;    
        n = before;
    }
    printf("%d\n",answer);
    return 0;
}
