type Fn = (...params: any[]) => Promise<any>;

// As we know of event loop concept and precence of callback queue and micro queue. When any of it is resolved it will come to the queue and executed
// The problem arises is that consider a million lines of code below it,which takes 12 sec to complete and t = 4 sec and promise resolved in 7 sec. In this case the answer must be time limit exceeded but the answer will be just opposite.
// This is because both are resolved before 12 sec waiting for call stack to be empty, as soon as call stack is empty, as fn promise is in micro queue it will given preference and executed.

function timeLimit(fn: Fn, t: number): Fn {
  return async function(...args) {
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);
      fn(...args).then(resolve).catch(reject);
    })
  }
};

// It clears the timeout as soon as fn resolves the promise.
function timeLimit2(fn: Fn, t: number): Fn {
  return async function(...args) {
    return new Promise((resolve, reject) => {
      const timeout = setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);
      fn(...args)
        .then(resolve)
        .catch(reject)
        .finally(() => clearTimeout(timeout));
    })
  }
};

// It uses inbuilt Promise.race method which resolves or give result of first one to be resolved in array
function timeLimit3(fn: Fn, t: number): Fn {
	return async function(...args) {
        let timeP = new Promise((res,rej)=>{
            setTimeout(()=>{
                rej("Time Limit Exceeded")
            },t)
        })
        let p = fn(...args);
        return Promise.race([p,timeP]);
    }
};