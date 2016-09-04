import java.util.*;

class BigModAlgorithm {

	public static void main(String args[]) {
		Scanner x = new Scanner(System.in);
		long base, power, mod;

		System.out.println("Input format: (a^b) % c");
		System.out.print("Base: ");
		base = x.nextLong();
		System.out.print("Power: ");
		power = x.nextLong();
		System.out.print("Mod: ");
		mod = x.nextLong();

		System.out.println(bigMod(base,power,mod));
	}

	private static long bigMod(long base, long power, long mod) {
		if(power==0)
			return 1;

		if(power%2!=0)
			return ((base%mod) * bigMod(base, power-1,mod)) % mod;

		else {
			long result = bigMod(base, power/2, mod);
			return ((result%mod) * (result%mod)) % mod;
		}
	}
}