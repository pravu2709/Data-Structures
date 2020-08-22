import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Hash {
	private String[] Table_hash;
	private int collision;
	private int load_val;
	public Hash(){
		Table_hash = new String[50];
		for(int i=0;i<50;i++)
			Table_hash[i] = null;
		collision = 0;
		load_val = 0;
		
	}
	public Hash(int n){
		Table_hash = new String[n];
		for(int i=0;i<n;i++)
			Table_hash[i] = null;
		collision = 0;
		load_val = 0;
		
	}
	
	public void load_val(File file) throws IOException{
		System.out.println("Initial Table Size = "+Table_hash.length);
		BufferedReader br = new BufferedReader(new FileReader(file));
		String word;
		while((word = br.readLine())!= null){
			add(word);
		}
		br.close();
	}
	
	public int code_hash(String word)
	{
		char[] a = word.toCharArray();
		int c = 0;
		for(int i = 0; i < a.length; i++)
		{
			 c += (int)a[i];
		}
		int h = 7;
		for(int i = 0; i< word.length();i++)
			h = h*31 + c;
		return c;
	}
	
	public void add(String word)
	{
		if(load_val+1 >=Table_hash.length)
			expandHash();
		int key_hash = code_hash(word)%Table_hash.length;
		if(Table_hash[key_hash]!= null)
			collision++;
		while(true){
			if(Table_hash[key_hash]== null){
				Table_hash[key_hash] = word;
				load_val++;
				break;
		}
		key_hash++;
		if (key_hash == Table_hash.length)
			key_hash =0;

	}
		
			
	}
	
	private void expandHash(){
		System.out.println("****** Table size being increased to = "+ Table_hash.length*2+" ***********");
		String[] table_backup = Table_hash;
		collision = 0;
		load_val = 0;
		Table_hash = new String[Table_hash.length*2];
		for(int i=0;i<table_backup.length;i++)
			if(table_backup[i]!=null)
				add(table_backup[i]);
	}
	
	boolean search_table(String word){
		int key_hash =  code_hash(word)%Table_hash.length;		
			if(Table_hash[key_hash]==null){
				return false;
			}
			else if(Table_hash[key_hash].equalsIgnoreCase(word)){
				return true;
			}
			while(Table_hash[key_hash]!=null){
					key_hash++;
					if(Table_hash[key_hash]==null)
						return false;
					if(Table_hash[key_hash].equalsIgnoreCase(word))
						return true;
					if(key_hash==Table_hash.length)
						key_hash = 0;
					if(key_hash== code_hash(word)%Table_hash.length)
						return false;
			}
		return false;
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Hash hash = new Hash(53);
		hash.load_val(new File("dictionary.txt"));
		System.out.println("Number of words inserted = "+hash.load_val);
		System.out.println("Number of collisions = "+hash.collision);
		String word;
		while(true){
			System.out.println("Please enter the word to search or type exit to end and exit the search :");
			word = br.readLine();
			if(word.equalsIgnoreCase("exit")){
				System.out.println("Thank you");
				System.exit(0);
			}
			if(hash.search_table(word))
				System.out.println("Match found for the word : "+word);
			else
				System.out.println("oops.... No match found!!!!");
		}
		

	}

}