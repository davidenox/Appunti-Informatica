- Aggiunta di StudenteInf
- aggiunta di abstract su StudentImpl
- modifica dei costruttori si StudentImpl con protected
- aggiunta del metodo "protected abstract String getFacultyCode();"



Codice di StudentImpl con Abstract
```java
package it.uniroma2.art.lmp.ex.model;

public abstract class StudentImpl extends PersonImpl implements Student {

	protected String matricola;
	static private int numStudenti = 0;
	
	protected StudentImpl(String nome, String cognome, String codiceFiscale) {
		
		super(nome, cognome, codiceFiscale);
		this.matricola = getFacultyCode() + ++numStudenti;
		
	}
	
	// overload
	protected StudentImpl(Person p) {
		this(p.getNome(), p.getCognome(), p.getCodiceFiscale());
	}
	
	@Override
	public String getMatricola() {
		return matricola;
	}
	
	public String toString() {
		return super.toString() + ", " + matricola;
	}

	@Override
	public void saluta(Professor prof) {
		// TODO Auto-generated method stub
		System.out.println("salve prof* " + prof);
	}

	@Override
	public void saluta(Professor prof, String appellativo) {
		// TODO Auto-generated method stub
		System.out.println("salve prof* " + prof + ", lei ï¿½ proprio un* " + appellativo); 
	}
	
	protected abstract String getFacultyCode();
	
}
```

Codice della classe StudentInf

```java
package it.uniroma2.art.lmp.ex.model;

public class StudenteInf extends StudentImpl implements Student {
	
	public StudenteInf(Person p) {
		this(p.getNome(), p.getCognome(), p.getCodiceFiscale());
		
	}
	
	public StudenteInf(String nome, String cognome, String codiceFiscale) {
		super(nome, cognome, codiceFiscale);
	}

	@Override
	protected String getFacultyCode() {
		return "inf";
	}

}
```

Modifica a StudentPsi

```java
package it.uniroma2.art.lmp.ex.model;

public class StudentePsi extends StudentImpl implements Student {
	
	public StudentePsi(Person p) {
		this(p.getNome(), p.getCognome(), p.getCodiceFiscale());
		
	}
	
	public StudentePsi(String nome, String cognome, String codiceFiscale) {
		super(nome, cognome, codiceFiscale);
	}

	@Override
	protected String getFacultyCode() {
		return "psi";
	}

}
```

