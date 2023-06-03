type F = (...p: any[]) => any;

// status is showing running state or completed state. So after completion reset state. If new request comes in-between then clear old and make new timer.
function debounce(fn: F, t: number): F {
  let status = 0;
  let timer;
  let val;

  return function (...args) {
    if (status === 1) {
      clearTimeout(timer);
      timer = setTimeout(() => {
        val = fn(...args);
        status = 0;
      }, t);
    } 
    else if(status === 0) {
      status = 1;
      timer = setTimeout(() => {
        status = 0;
        val = fn(...args);
      }, t);
    }

    return val;
  };
}
