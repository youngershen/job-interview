# Project: JobInterview
# File : test.py
# Date : 2023/6/1 17:28
# Author: Younger Shen <申延刚>
# Web: https://github.com/youngershen
# Cell: 13811754531
# Wechat: 13811754531
# Email : shenyangang@163.com

import copy

copy.deepcopy()


class Singleton:
    def __new__(cls):
        pass


# 求和问题
def find(l: list, t: int):
    for i in range(0, len(l)):
        for j in range(0, len(l)):
            if t == l[i] + l[j] and i != j:
                return i, j

    return None


if __name__ == '__main__':
    l1 = [3, 3, 3, 3]
    target = 6
    r = find(l1, target)
    print(r)

    s = Singleton.initial()