// Currying is a powerful technique in functional programming that transforms a function with multiple arguments into a sequence of functions. It allows you to create flexible and reusable code by enabling partial application of function arguments. In this article, we will discuss the concept and implementation of currying in JavaScript.


// If the given argument length is equal to or greater that required argument length then simply apply the function.
// else return another function which takes the remaining arguments and have previous given argument prefilled.
function curry(fn: Function): Function {
    return function curried(...args:any[]) : any {
        if(args.length >= fn.length){
            return fn(...args);
        }
        return (...remainingArgs:any[]) : any=>{return curried(...args,...remainingArgs)}
    };
};

// Same above approach using bind method which also returns function
function curry2(fn: Function): Function {
    return function curried(...args:any[]) : any {
        if(args.length >= fn.length){
            return fn(...args);
        }
        return curried.bind(this,...args)
    };
};

