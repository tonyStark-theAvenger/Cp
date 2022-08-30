function solve(x) {
    x *= 2;
    return function two(y) {
        y *= x;

    }
    return function three(z) {

        z *= y;
    }
}

