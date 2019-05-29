# -*- coding: utf-8 -*-
import math
aa = input()
print('%2d-%02d' % (3, 1))
print('%.2f' % 3.1415926)
print('Age: %s. Gender: %s' % (25, True))
print('growth rate: %d %%' % 7)
print('Hello, {0}, 成绩提升了 {1:.1f}%'.format('小明', 17.125))
s1 = 72
s2 = 85
r = (s2 - s1) / s1 * 100
print('%d' % (s1//s2))
print('%.2f%%' % (r))
classmates = ['A', True, 'C']
print(classmates[-1])
classmates.append('D')
print(classmates)
classmates.insert(1, '哈哈')
print(classmates)
classmates.pop(1)
print(classmates)
s = ['python', 'java', ['asp', 'php'], 'scheme']
L = []
print(len(L))
t = (1,)
print(len(t))
LL = [
    ['Apple', 'Google', 'Microsoft'],
    ['java', 'python', 'Ruby', 'PHP'],
    ['Adam', 'Bart', 'Lisa']
]
for name in LL[0]:
    print('hello', name)
age = 1
if age >= 18:
    print('13');
    print('88')
elif age < 3:
    print('1320')
    print(789)
d = {'A':123, 'B':75, 'C':1230}
print(d['B'])
d = {(1, 2, 3)}
def xxx(a, b, c):
    x1 = (-b + math.sqrt(b**2 - 4 * a * c)) / (2 * a)
    x2 = (-b - math.sqrt(b**2 - 4 * a * c)) / (2 * a)
    return x1, x2
x, y = xxx(1, 3, -4)
print(x, y)
def cal(*nums):
    sum = 1
    for i in nums:
        sum = sum * i
    return sum
ll = (1, 2, 3, 4)
tt = cal(*ll)
print(tt)
def move(n, a, b, c):
    if n == 1 :
        print(a, '-->', c)
    else:
        move(n - 1, a, c, b)
        print(a, '-->', c)
        move(n - 1, b, a, c)
move(3, 'A', 'B', 'C')