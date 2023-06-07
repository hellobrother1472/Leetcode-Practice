type F = (x: number) => number;

function compose(functions: F[]): F {
	return function(x) {
        let ans:number = x;
        for(let i = functions.length-1; i >= 0; i--){
            ans = functions[i](ans);
        }
        return ans;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */