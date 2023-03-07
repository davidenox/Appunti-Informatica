Ritornando a [[LMP 1]]. aggiunta di due sottoclassi a StudentImpl, ovvero StudentePsicologia e StudenteChimica
Modifica di StudentImpl (viene tolta la matricola passatta in modo statico e viene aggiunta la var numStudenti che si incrementa da sola)

AngryStudent viene cancellato

Codice Modificato di StudentImpl
```java
package it.uniroma2.art.lmp.ex.model;

public class StudentImpl extends PersonImpl implements Student {
	protected String matricola;
	static private int numStudenti=0;
	public StudentImpl(String nome, String cognome, String codiceFiscale) {
		super(nome, cognome, codiceFiscale);
		this.matricola = ""+ ++numStudenti;
	}
	public StudentImpl(Person p) {
		this(p.getNome(),p.getCognome(),p.getCodiceFiscale());
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

Codice StudentePsicologia
```java
package it.uniroma2.art.lmp.ex.model;

public class StudentePsicologia extends StudentImpl implements Student {

	public StudentePsicologia(Person p) {
		//super(p);
		// TODO Auto-generated constructor stub
		this(p.getNome(), p.getCognome(), p.getCodiceFiscale());
	}
	
	public StudentePsicologia(String nome, String cognome, String codiceFiscale) {
		super(nome, cognome, codiceFiscale);
		matricola = "Psicologia"+matricola;
	}	
}
```

Codice Main
```java
package it.uniroma2.art.lmp.ex;

import it.uniroma2.art.lmp.ex.model.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Person franco=new PersonImpl("Franco","Salvucci","asdasfafacs");

		Student francostudent = new StudentImpl(franco);
		//invoca il metodo toString dell'oggetto
		System.out.println(francostudent);
		Student francostudent2 = new StudentImpl(franco);
		//invoca il metodo toString dell'oggetto
		System.out.println(francostudent2);
		Professor stellato = new ProfessorImpl("Armando","Stellato","lcasasf","LMP");
		System.out.println(stellato);
		
		francostudent.saluta(stellato, "xxxx");
		Student franco_psi = new StudentePsicologia(franco);
		System.out.println(franco_psi);
	}
}
```

