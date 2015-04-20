import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Vector;

public class quina {
	
	Vector<Vector<Integer>> apuestas = new Vector<Vector<Integer>>();
	Vector<Vector<Integer>> resultados = new Vector<Vector<Integer>>();
	
	public quina()
	{
		init(apuestas, "C:\\Users\\Daniel\\workspace\\Trabajo3\\ejemplo-quina\\apuestas.txt");
		init(resultados, "C:\\Users\\Daniel\\workspace\\Trabajo3\\ejemplo-quina\\resultados.txt");
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
						linea.add(Integer.valueOf(word));
						word = "";
					}
				}
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
		double precio1 = 0.75;
		double precio2 = 3.00;
		double precio3 = 7.50;
		
		double monto = 0;
		double pozo = 0.00;
		
		int quina = 0;
		int quadra = 0;
		int terno = 0;
		
		double quina_precio;
		double quadra_precio;
		double terno_precio;
		
		for(int i = 0; i < apuestas.size(); i++)
		{
			if(apuestas.get(i).size() == 5)
				monto += precio1;
			else if(apuestas.get(i).size() == 6)
				monto += precio2;
			else if(apuestas.get(i).size() == 7)
				monto += precio3;
		}
		
		pozo = (32.20 * monto) / 104.5;
		
		for(int i = 0; i < apuestas.size(); i++)
		{
			int aciertos = 0;
			Vector<Integer> repetido = new Vector<Integer>();
			for(int j = 0; j < apuestas.get(i).size(); j++)
			{
				for(int a = 0; a < resultados.get(0).size(); a++)
					if(resultados.get(0).get(a).equals(apuestas.get(i).get(j)))
					{
						if(repetido.isEmpty())
						{
							aciertos++;
							repetido.add(resultados.get(0).get(a));
						}
						else
						{
							Boolean flag = true;
							for(int b = 0; b < repetido.size(); b++)
							{
								if(apuestas.get(i).get(j).equals(repetido.get(b)))
									flag = false;
							}
							if(flag)
							{
								aciertos++;
								repetido.add(resultados.get(0).get(a));
							}
						}
					}
			}
			
			if(aciertos >= 5)
				quina++;
			else if(aciertos == 4)
				quadra++;
			else if(aciertos == 3)
				terno++;
		}
		
		quina_precio = (35 * pozo) / 100;
		quadra_precio = (25 * pozo) / 100;
		terno_precio = quadra_precio;
		
		DecimalFormat df = new DecimalFormat("###.##");
		
		System.out.println(monto);
		System.out.println(df.format(pozo));
		System.out.println("Quina " + quina + " " + df.format(quina_precio/quina));
		System.out.println("Quadra " + quadra + " " + df.format(quadra_precio/quadra));
		System.out.println("Terno " + terno + " " + df.format(terno_precio/terno));
	}
}
