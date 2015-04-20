import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Vector;


public class lotogol {
	
	Vector<Vector<Integer>> apuestas = new Vector<Vector<Integer>>();
	Vector<Vector<Integer>> resultados = new Vector<Vector<Integer>>();
	
	public lotogol()
	{
		init(apuestas, "C:\\Users\\Daniel\\workspace\\Trabajo3\\ejemplo-lotogol\\apuestas.txt");
		init(resultados, "C:\\Users\\Daniel\\workspace\\Trabajo3\\ejemplo-lotogol\\resultados.txt");
	}
	
	public void init(Vector<Vector<Integer>> fi, String path)
	{
		try (BufferedReader br = new BufferedReader(new FileReader(path)))
		{
 
			String sCurrentLine;
			String word = "";
 
			while ((sCurrentLine = br.readLine()) != null) {
				
				Vector<Integer> linea = new Vector<Integer>();
				
				for(int i = 0; i < sCurrentLine.length(); i++)
				{
					if(sCurrentLine.charAt(i) != ' ')
						word += String.valueOf(sCurrentLine.charAt(i));
					else
					{
						if(word.equals("+"))
							word = "-1";
						
						linea.add(Integer.valueOf(word));
						word = "";
					}
				}
				
				if(word.equals("+"))
					word = "-1";
				
				linea.add(Integer.valueOf(word));
				word = "";				
				fi.add(linea);
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void print(Vector<Vector<Integer>> m)
	{
		for(int i = 0; i < m.size(); i++)
		{
			for(int j = 0; j < m.get(i).size(); j++)
				System.out.print(m.get(i).get(j) + " ");
			System.out.println();
		}
	}
	
	public void juego()
	{
		double precio1 = 0.50;
		double precio2 = 1.00;
		double precio3 = 2.00;
		
		double monto = 0;
		double pozo;
		
		int res5 = 0;
		int res4 = 0;
		int res3 = 0;
		
		double res5_precio;
		double res4_precio;
		double res3_precio;
		
		for(int i = 0; i < apuestas.size(); i++)
		{
			if(apuestas.get(i).get(0) == 1)
				monto += precio1;
			else if(apuestas.get(i).get(0) == 2)
				monto += precio2;
			else if(apuestas.get(i).get(0) == 4)
				monto += precio3;
		}
		
		pozo = (28 * monto) / 104.5;
		
		for(int i = 0; i < apuestas.size(); i++)
		{
			int aciertos = 0;
			Vector<Integer> repetido = new Vector<Integer>();
			
			for(int j = 1; j <= (apuestas.get(i).size()-1); j = j + 2)
			{
				for(int a = 0; a <= resultados.get(0).size()-2; a = a + 2)
				{
					if(resultados.get(0).get(a).equals(apuestas.get(i).get(j)) &&
					   resultados.get(0).get(a+1).equals(apuestas.get(i).get(j+1)))
					{
						if(repetido.isEmpty())
						{
							aciertos++;
							repetido.add(resultados.get(0).get(a));
							repetido.add(resultados.get(0).get(a+1));
						}
						else
						{
							Boolean flag = true;
							for(int b = 0; b <= repetido.size()-2; b = b + 2)
							{
								if(apuestas.get(i).get(j).equals(repetido.get(b)) &&
								   apuestas.get(i).get(j+1).equals(repetido.get(b+1)))
									flag = false;
							}
							if(flag)
							{
								aciertos++;
								repetido.add(apuestas.get(i).get(j));
								repetido.add(apuestas.get(i).get(j+1));
							}
						}
					}
				}
			}
			
			if(aciertos == 5)
				res5++;
			else if(aciertos == 4)
				res4++;
			else if(aciertos == 3)
				res3++;
		}
		
		res5_precio = (40 * pozo) / 100;
		res4_precio = (30 * pozo) / 100;
		res3_precio = res4_precio;
		
		DecimalFormat df = new DecimalFormat("###.##");
		
		System.out.println(monto);
		System.out.println(df.format(pozo));
		System.out.println("1° (5 aciertos) " + res5 + " " + df.format(res5_precio/res5));
		System.out.println("2° (4 aciertos) " + res4 + " " + df.format(res4_precio/res4));
		System.out.println("3° (3 aciertos) " + res3 + " " + df.format(res3_precio/res3));
	}

}
