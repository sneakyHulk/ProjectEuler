# Combinatoric Selections

### Problem 53

There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, <span class="supsub"><sup>5</sup><sub>3</sub></span> = 10.

In general, <span class="supsub"><sup>5</sup><sub>3</sub></span> = <span class="division"><sup>n!</sup><sub>r!(n - r)!</sub></span>, where r ≤ n, n! = n x (n - 1) x ... x 3 x 2 x 1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million: <span class="supsub"><sup>23</sup><sub>10</sub></span> = 1144066.

How many, not necessarily distinct, values of <span class="supsub"><sup>n</sup><sub>r</sub></span> for 1 ≤ n ≤ 100, are greater than one-million?

---

Answer:  4075

Completed on Wed, 25 Oct 2023, 01:13

<style>

.supsub {
    display: inline-flex;
    flex-direction: column;
    vertical-align: middle;
    margin: -3.5em 0.4em -3.5em 0.4em;
    text-align: center;
}

.supsub:before {
    position: relative;
    content: "(";
    text-align: left;
    font-size: 1.8em;
    top: 1.45em;
    right: 0.35em;
}

.supsub:after {
    content: ")";
    text-align: right;
    position: relative;
    right: 0.2em;
    font-size: 1.8em;
    bottom: 1.60em;
    left: 0.35em;
}

.division {
    display: inline-flex;
    flex-direction: column;
    vertical-align: middle;
    text-align: center;
}

.division sup {
    border-bottom:2px solid;
}
</style>