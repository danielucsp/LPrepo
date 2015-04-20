import java.util.Scanner;

import javax.print.DocFlavor.INPUT_STREAM;

public class main {

	/**
	 * @param args
	 */
	static quina q;
	static lotogol l;
	public static void main(String[] args) {
		String param1 = new String();
		String param2 = new String();
		
		Scanner input = new Scanner(System.in);
		param1 = input.nextLine();
		param2 = input.nextLine();
		
		if(param1.equals("quina") && param2.equals("ejemplo-quina"))
		{
			q = new quina();			
			q.juego();
		}
		
		if(param1.equals("lotogol") && param2.equals("ejemplo-lotogol"))
		{
			l = new lotogol();
			l.juego();
		}
		 
	}

}