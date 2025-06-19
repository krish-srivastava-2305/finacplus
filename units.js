class OptimizedUnits {
    constructor(units) {
        this.units = units;
        this.dp = Array.from({ length: 100 }, () => Array(101).fill(-1));
    }

    getCoins(amt, i, units) {
        if (amt === 0) return 0;
        if (amt < 0 || i >= units.length) return 1e9;

        if (this.dp[i][amt] !== -1) return this.dp[i][amt];

        let take = 1e9;
        const sol = this.getCoins(amt - units[i], i, units);
        if (sol !== 1e9) take = 1 + sol;

        let skip = this.getCoins(amt, i + 1, units);

        return this.dp[i][amt] = Math.min(take, skip);
    }

    findAverage() {
        let numCoins = 0;
        for (let amt = 1; amt <= 99; amt++) {
            numCoins += this.getCoins(amt, 0, this.units);
        }
        this.dp = Array.from({ length: 100 }, () => Array(101).fill(-1));
        return numCoins / 99;
    }
}

const units = [1, 2, 5, 10, 20, 50];
const res = new OptimizedUnits(units);
console.log("Average coins used:", res.findAverage().toFixed(4)); // Output: 3.4343
