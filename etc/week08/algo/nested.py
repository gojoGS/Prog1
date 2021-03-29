#!/usr/bin/env python3
import itertools

# A typusok elhagyhatóak


def nested(s: str) -> int:

    # Megj.: ezt a függvény be lehetne cserélni egy dict-re de maradjon az egyszerűség kedvéért
    def value(c: str) -> int:
        if c == '(':
            return 1
        elif c == ')':
            return -1
        else:
            return 0

    # Ugyanazt az eredményt adja, mint a return max(list(...)) sor
    # Csak egy kicsivel szellősebb
    # És list comprehensiont használ map helyett
    #
    # lst = [value(c) for c in s]
    # lst = list(itertools.accumulate(lst))
    # return max(lst)

    return max(list(itertools.accumulate(map(value, s))))


def main():
    tests = ['3 + 4', '(2 * 3)', '((((()))))', '((3 + 2) * ((4 +2) * 5))']

    for case in tests:
        print('Nesting of "{}" is {}'.format(case, nested(case)))


if __name__ == '__main__':
    main()
