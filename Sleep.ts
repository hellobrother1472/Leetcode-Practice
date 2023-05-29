// Resolving a function after millis second
async function sleep(millis: number): Promise<void> {
	return new Promise((res, rej) => {
		try {
			setTimeout(() => res(), millis);
		} catch (err) {
			rej(err);
		}
	});
}
