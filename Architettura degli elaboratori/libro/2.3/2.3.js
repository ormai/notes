// ci ha messo 9:05 minuti a completare

function main() {
    for (let i = 0; i < 50; i++) {
        console.log(f(i));
    }
}

function f(n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return Math.round((2*f(n-1)) - (f(n-2)/2));
}

main();
