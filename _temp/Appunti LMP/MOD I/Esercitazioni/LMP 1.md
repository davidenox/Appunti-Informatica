Ritornando a [[LMP 0]], inseriamo le classi ProfessorImpl e StudentImpl e AngryStudent e le interfacce corrispondenti, ovvero Student e Professor

Codice di Student
```java
package it.uniroma2.art.lmp.ex.model;

public interface Student extends Person {
	public String getMatricola();
	public void saluta(Professor prof);//overload a più livelli
	public void saluta(Professor prof,String appellativo);
}

```
faccio extends Person per estendere l'interfaccia Student all'interfaccia Person, per prendere tutti i metodi di Person. 
Faccio la stessa cosa con Professor

Codice di Professor
```java
package it.uniroma2.art.lmp.ex.model;

public interface Professor extends Person{
	public String getCattedra();
}

```

Codice di StudentImpl
```java
package it.uniroma2.art.lmp.ex.model;

public class StudentImpl extends PersonImpl implements Student {
	
	private String matricola;
	
	public StudentImpl(String nome, String cognome, String codiceFiscale,String matricola) {
		super(nome, cognome, codiceFiscale);
		this.matricola = matricola;
	}
	
	public StudentImpl(Person p,String matricola) {
		this(p.getNome(),p.getCognome(),p.getCodiceFiscale(),matricola);
	}
	@Override
	public String getMatricola() {
		return matricola;
	}
	
	public String toString() {
		return super.toString()+" "+matricola;
	}

	@Override
	public void saluta(Professor prof) {
		// TODO Auto-generated method stub
		System.out.println("Salve prof: "+prof);
	}

	@Override
	public void saluta(Professor prof, String appellativo) {
		// TODO Auto-generated method stub
		System.out.println("Salve prof: "+prof+" lei è proprio un " + appellativo);
	}
}
```

Codice di ProfessorImpl

```java
package it.uniroma2.art.lmp.ex.model;

/**
 * @author franc
 *
 */
public class ProfessorImpl extends PersonImpl implements Professor {

	/**
	 * @param nome
	 * @param cognome
	 * @param codiceFiscale
	 */
	private String cattedra;
	//esempio di overloading (meglio non farlo)
	public ProfessorImpl(String nome, String cognome, String codiceFiscale) {
		super(nome, cognome, codiceFiscale);
	}
	public ProfessorImpl(String nome, String cognome, String codiceFiscale,String cattedra) {
		//super(nome, cognome, codiceFiscale);
		this(nome,cognome,codiceFiscale);
		this.cattedra = cattedra;
	}
	@Override
	public String getCattedra() {
		return cattedra;
	}
	
	public void setCattedra(String cattedra) {
		this.cattedra = cattedra;
	}
	
	public String toString() {
		return super.toString() + " " + ((cattedra!=null)?cattedra:"");//espressione compatta per if-then-else
	}
}
```

Codice di AngryStudent
```java
package it.uniroma2.art.lmp.ex.model;

public class AngryStudent extends StudentImpl implements Student {

	public AngryStudent(String nome, String cognome, String codiceFiscale, String matricola) {
		super(nome, cognome, codiceFiscale, matricola);
	}

	public AngryStudent(Person p, String matricola) {
		super(p, matricola);
	}
	//overide del metodo saluta della superclasse
	public void saluta(Professor prof) {
		this.saluta(prof,"xxx");
	}
}
```


>[!info]- Osservazione
>**Late Binding**: l'esecuzione avviene più tardi; il compilatore non decide il metodo da chiamare. L'override è un perfetto esempio di late binding. 
>Processo a runtime, quando java invoca il metodo dell'oggetto, guarda l'implementazione
>Quando il tipo dell'oggetto viene determinato in fase di esecuzione, è noto come Late Binding
>Spiegazione qui -->[Late-Binding](http://www.diag.uniroma1.it//liberato/laboratorio/late/late.html)







