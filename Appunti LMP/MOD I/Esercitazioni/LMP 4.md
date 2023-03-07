# Parte 1

- Aggiunta della classe CorsoDiStudi
- Modifica della classe StudentImpl
	- aggiunta dei campo corsodistudi e annodicorso
	- modifica dei costruttori
	- aggiunta dei metodi getAnnoDiCorso e getCorsoDiStudi
- Modifica dell'interfaccia Student

Codice della classe CorsoDiStudi

```java
package it.uniroma2.art.lmp.ex.model;

public enum CorsoDiStudi {
    INFORMATICA("INF"),
    INGEGNERIA("ING"),
    PSICOLOGIA("PSI");
    private String codice;

    CorsoDiStudi(String codice){
        this.codice = codice;
    }
    public String getCode(){
        return codice;
    }
}
```

Codice modificato di StudentImpl

```java
package it.uniroma2.art.lmp.ex.model;

public class StudentImpl extends PersonImpl implements Student {
    
    protected String matricola;
    static private int numStudenti = 0;
    private CorsoDiStudi corsoDiStudi;
    private int annoDiCorso;
    
    public StudentImpl(String nome, String cognome, String codiceFiscale,
            CorsoDiStudi corso, int annoDiCorso) {
        super(nome, cognome, codiceFiscale);
        this.corsoDiStudi = corso;
        this.annoDiCorso = annoDiCorso;
        this.matricola = corsoDiStudi.getCode() + ++numStudenti;
    }
    // overload
    public StudentImpl(Person p, CorsoDiStudi corso, int annoDiCorso) {
        this(p.getNome(), p.getCognome(), p.getCodiceFiscale(), corso, annoDiCorso);
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
        System.out.println("salve prof* " + prof + ", lei è proprio " + appellativo);
    }
    @Override
    public int getAnnoDiCorso() {
        return annoDiCorso;
    }
    @Override
    public CorsoDiStudi getCorsoDiStudi() {
        return corsoDiStudi;
    }
}
```

Codice modificato di Student

```java
package it.uniroma2.art.lmp.ex.model;

public interface Student extends Person {

    String getMatricola();
    int getAnnoDiCorso();
    CorsoDiStudi getCorsoDiStudi();
    // overload
    void saluta(Professor prof);
    void saluta(Professor prof, String appellativo);
}
```

----
# Parte 2

- Introduzione al design pattern delle factory
	- Il nome contiene la parola "factory", es. "University_factory"
- Aggiunta dell'interface University (è la nostra factory)
- Costruttori di StudentImpl messi **package protected** (tolgo il public) (il runner.java non crea più gli studenti)
- Modifica generale di StudentImpl
- Modifica del Runner
- Eliminazione di StudentInf e StudentPsi
- Aggiunta della classe UniversityImpl
- Aggiunta ed utilizzo della struttura dati Map (fa parte delle Collections, vedi Lezione 13)
	- ```Map<String,Student> iscritti```
- Aggiunta dei metodi getStudente e disiscriviStudente (tramite la matricola, vanno a fare rispettivamente una put nella Map e un remove)
- Aggiunta di una eccezione custom per il remove dello studente (classe StudentNotFoundException)

Codice della factory
```java
package it.uniroma2.art.lmp.ex.model;

public interface University {
	public Student iscriviStudente(String nome, String cognome, String codiceFiscale,
            CorsoDiStudi corso, int annoDiCorso);
	
	// overload
    public Student iscriviStudente(Person p, CorsoDiStudi corso, int annoDiCorso); 
	
    public int getNumeroIscritti();
    
    public Student getStudente(String matricola);
    
    public void disiscriviStudente(String matricola) throws StudentNotFoundException;
    
}
```

Modifica di StudentImpl

```java
package it.uniroma2.art.lmp.ex.model;

public class StudentImpl extends PersonImpl implements Student {

	protected String matricola;
	//static private int numStudenti = 0;
	private CorsoDiStudi corsoDiStudi;
    private int annoDiCorso;
    
    /*Il costruttore è stato messo package protected*/
    StudentImpl(String nome, String cognome, String codiceFiscale,
            CorsoDiStudi corso, String matricola,int annoDiCorso) {
        super(nome, cognome, codiceFiscale);
        this.corsoDiStudi = corso;
        this.annoDiCorso = annoDiCorso;
        //this.matricola = corsoDiStudi.getCode() + ++numStudenti;
        this.matricola = matricola;
    }
	
	// overload
    StudentImpl(Person p, CorsoDiStudi corso,String matricola,int annoDiCorso) {
        this(p.getNome(), p.getCognome(), p.getCodiceFiscale(), corso, matricola, annoDiCorso);
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
	
	@Override
    public int getAnnoDiCorso() {
        return annoDiCorso;
    }
    @Override
    public CorsoDiStudi getCorsoDiStudi() {
        return corsoDiStudi;
    }
	
}
```

Modifica di Runner

```java
package it.uniroma2.art.lmp.ex;

import it.uniroma2.art.lmp.ex.model.*;

/**
 * @author Andrea
 * 
 * <p>questa ï¿½ la classe di avvio dell'esercizio di lmp</p>
 * 
 */
public class Runner {
	
	/**
	 * @param args
	 */
	
	public static void main(String[] args) {
		
		University torVergata = new UniversityImpl();
		Person mario = new PersonImpl("Mario","Rossi","0298126");
		Person franco = new PersonImpl("Franco","Salvucci","035410");
		 
		System.out.println(mario);
		mario.saluta();
		
		Professor stellato = new ProfessorImpl("Armando","Stellato","437388383","LMP");
		System.out.println(stellato);
		
		/*Student mariostudent = new StudentImpl(mario,CorsoDiStudi.INFORMATICA,2);
		mariostudent.saluta(stellato,"gentilissimo");
		System.out.println(mariostudent);*/
		
		Student mariostudent = torVergata.iscriviStudente(mario, CorsoDiStudi.INFORMATICA, 2);//torVergata aè la factory
		//mariostudent.saluta(stellato,"gentilissimo");
		System.out.println(mariostudent);
		
		Student francostudent = torVergata.iscriviStudente(franco, CorsoDiStudi.INFORMATICA, 2);//torVergata aè la factory
		//francostudent.saluta(stellato,"gentilissimo");
		System.out.println(francostudent);
		
		System.out.println("A Tor Vergata sono iscritti: "+torVergata.getNumeroIscritti()+" studente/i");
		
		System.out.println("Recupero lo studente INF_1: "+torVergata.getStudente("INF_1"));
		try {
			torVergata.disiscriviStudente("INF_3");
			System.out.println("Ho rimosso INF_3");
		} catch (StudentNotFoundException e) {
			System.err.println(e.getMessage());
		}
		
		try {
			torVergata.disiscriviStudente("INF_2");
			System.out.println("Ho rimosso INF_2");
		} catch (StudentNotFoundException e) {
			System.err.println(e.getMessage());
		}
		System.out.println("A Tor Vergata sono iscritti: "+torVergata.getNumeroIscritti()+" studente/i");
		
	}

}
```

Codice di UniversityImpl

```java
package it.uniroma2.art.lmp.ex.model;

import java.util.HashMap;
import java.util.Map;

public class UniversityImpl implements University{

	int contatore_matricola=0;

	Map<String,Student> iscritti = new HashMap<String, Student>();//mappa,HashMap implementazione di Map
	@Override
	public Student iscriviStudente(String nome, String cognome, String codiceFiscale, CorsoDiStudi corso,
			int annoDiCorso) {
		String matricola = corso.getCode() + "_" + ++contatore_matricola;
		Student s = new StudentImpl(nome,cognome,codiceFiscale,corso,matricola,annoDiCorso);
		iscritti.put(matricola, s);
		return s;
	}

	@Override
	public Student iscriviStudente(Person p, CorsoDiStudi corso, int annoDiCorso) {

		return iscriviStudente(p.getNome(),p.getCognome(),p.getCodiceFiscale(),corso,annoDiCorso);
	}
	@Override
	public int getNumeroIscritti() {
		return iscritti.size();
	}

	@Override
	public Student getStudente(String matricola) {
		
		return iscritti.get(matricola);
	}

	@Override
	public void disiscriviStudente(String matricola) throws StudentNotFoundException {
		if(iscritti.remove(matricola) == null) throw new StudentNotFoundException(matricola);
	}
	
}
```

Classe dell'eccezione custom per la gestione del remove dello studente
```java
package it.uniroma2.art.lmp.ex.model;

public class StudentNotFoundException extends Exception {
	public StudentNotFoundException(String matricola) {
		super("Lo studente con matricola: "+matricola+" non esiste");
	}
}
```

