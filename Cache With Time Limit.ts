// c is count and obj is the object where key-obj(value,timer) is stored.
// The logic is that whenever set is called we make the key with the another nested obj which contains it's value and the setTimeout (The fucntion of setTimeout is to set the value to -1 and decrease count after time passes).

class TimeLimitedCache {
    constructor() {

    }
    c = 0;
    obj = {};

    timeO(key:number, duration:number){
        let timer = setTimeout(()=>{
            if(key in this.obj) this.obj[key].val = -1;
            this.c--;
        },duration);
        return timer; // returning timer
    }

    set(key: number, value: number, duration: number): boolean {
        if (key in this.obj) { // checking if already exist
            if (this.obj[key].val === -1) this.c++; // if value's timer already expired it means c also decreased so increase c as we are giving a new life, a new value to the key.
            clearTimeout(this.obj[key].timer); // Use clearTimeout() to clear the timeout if their is already running a previous timer and we change in between so we first need to clear that timer. c value remains same as we are just chaning the value.
            this.obj[key].val = value; // Then change value
            this.obj[key].timer = this.timeO(key, duration); // Then add another new timer
            return true;
        }

        this.obj[key] = {}; // Initialize this.obj[key] as an object
        this.obj[key].val = value; // Adding the value
        this.c++; // Increasing the count
        this.obj[key].timer = this.timeO(key, duration); // assigning the timer
        return false;
    }

    get(key: number): number {
        if(!(key in this.obj)) return -1;
        return this.obj[key].val;
    }

	count(): number {
        return this.c;
    }
}

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */