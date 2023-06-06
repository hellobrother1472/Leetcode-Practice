type F = () => Promise<any>;

// In this approach we are using reccursion. We are using two variables i for iterating in functions array and count which takes account of pool.
// every time the functions is executed count increses and as soon as it resolved count decreases and reccursively call helper.
function promisePool(functions: F[], n: number): Promise<any> {
    return new Promise((res)=>{
        let i = 0;
        let count = 0;
        function helper(){
            if(i >= functions.length){
                if(count == 0) res("random");
                return
            }
            while(count < n && i < functions.length){
                count++;
                const promise = functions[i]();
                i++;
                promise.then(()=>{
                    count--;
                    helper();
                })
            }
        }
        helper();
    })
};

// next() function is the function which executes takes the first function executes it and wait for it and if it gets executed it will again invoke itself.
// So first we are creating an array of size n, we fill it with dummy value say 0 for all the places, then we map through each of index and run next() function. The benifit of this is that the n functions are executed at a single time and whenever a function complete it's execution it will again call next() and add another function to execution
// After that we are using Promise.all which resolves at when all the promises in the given array resolves.
async function promisePool2(functions: F[], n: number): Promise<any> {
    async function next(){
        if(functions.length == 0) return
        let fn:any = functions.shift(); // shift (means remove first function) and return the first function
        await fn() // wait for execution
        await next() // after execution do another execution so that pool be full
    }
    let nPromise = Array(n).fill(0).map(next);
    await Promise.all(nPromise)

};

// Instead of checking if there are functions left to execute with an if statement, we can use optional chaining on the function call (functions[n++]?.()). This syntax immediately returns undefined if functions[n++] is null or undefined. Without this syntax, an error would be thrown.
async function promisePool3(functions: F[], n: number): Promise<any> {
    const evaluateNext = () => functions[n++]?.().then(evaluateNext); 
    return Promise.all(functions.slice(0, n).map(f => f().then(evaluateNext)));
};
