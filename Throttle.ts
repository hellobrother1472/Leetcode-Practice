// We can keep track of a variable nextTimeToCallFn representing the point in time we should call fn next.

// Every time the throttled function is called, we should create a new timeout such that it is executed at nextTimeToCallFn. In order to achieve this result, the formula for the delay passed to setTimeout is simply nextTimeToCallFn - Date.now(). Notice that if fn hadn't been called in a while, the delay becomes negative. In that situation, we should instead immediately call fn (delay is 0).

// Every time fn is called, we should set nextTimeToCallFn to be Date.now() + t.

// Also, before creating a new timeout, we need to clear the existing timeout if it exists. That way, at most one timeout is running at any given time.

function throttle(fn: F, t: number): F {
	let timeout: undefined | number = undefined;
	let nextTimeToCallFn = 0;
	return function (...args) {
		const delay = Math.max(0, nextTimeToCallFn - Date.now());
		clearTimeout(timeout);
		timeout = setTimeout(() => {
			nextTimeToCallFn = Date.now() + t;
			return fn(...args);
		}, delay);
	};
}


