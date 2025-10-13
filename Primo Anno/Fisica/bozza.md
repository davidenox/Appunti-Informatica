# 1 Cinetica e Moti

## Moto Rettilineo Uniforme

Velocità costante
- **Legge Oraria** : $x_f(t)=x_i\cdot V_x(t)$
- Velocità media $V_{x,med}$ uguale a velocità instantanea costante 

## Moto Accelerato

- **Velocità Istantanea** istante $t_i$ : $V_x(t_i)=V_{x,i}$
- **Accelerazione Media** : $a_{x,med}=\frac{V_{xf}-V_{xi}}{t_f-t_i}$
- **Accelerazione Istantanea** : $a_x(t_i)=[V_x(t)]'=[x(t)]''$
## Moto Rettilineo Uniformemente Accellerato

- **Accelerazione media = accelerazione istantanea** $a_{x,med}=a_x$
- **Velocità** : $V_x(t)=V_{x0}+a_xt$
- **Legge oraria** : $x(t)=x_0+V_{x0}+\frac{1}{2}a_xt^2$
- **Gravità** : $g=9.81\frac{m}{s^2}$, se corpo sale $a_x=-g$, altrimenti $a_x=g$
## Vettori

- **Modulo Vettore** : $\left|\vec{V}\right|$
- **Vettore** : $\vec{V}$
- **Direzione, Verso** : Retta lungo la quale giace il vettore, orientamento del vettore
- **Componenti Vettore** : $\vec{V}_x,\vec{V}_y$
	- $V_x=V\cos(\theta),V_y=\sin(\theta)$
- **Fase del vettore** : Angolo $\theta\implies\arctan(\frac{V_y}{V_x}),V_x\gt0;\arctan(\frac{V_y}{V_x})+\pi,V_x\lt0$
## Moto Bidimensionale

Accelerazione costante

- **Vettore spostamento del corpo** : $\Delta\vec{r}=\vec{r}_f-\vec{r}_i$
- **Velocità media** : $\Delta\vec{V}_{med}=\frac{\Delta\vec{r}}{\Delta t}$
- **Velocità istantanea** : $\vec{V}=[\vec{r}(t)]'$
	- Comp x : $V_x(t)=V_{x0}+a_xt$
	- Comp y : $V_y(t)=V_{y0}+a_yt$
- **Accelerazione media** : $\vec{a}_{med}=\frac{\Delta\vec{V}}{\Delta t}$
- **Accelerazione istantanea** : $\vec{a}=[\vec{r}(t)]''$
- **Legge oraria** : $\vec{r(t)}=\vec{r_0}+\vec{V_0}t+\frac{1}{2}\vec{a}t^2$
	- Comp x : $x(t)=x_0+V_{x0}t+\frac{1}{2}a_xt^2$
	- Comp y : $y(t)=y_0+V_{y0}t+\frac{1}{2}a_yt^2$
### Moto Proiettile
$\vec{a}=\vec{g}$ verso il basso costante; istante $t=0$ il corpo si trova in pos $(0,0)$ con velocità $\vec{V_0}$ che forma angolo $\theta_0$ con semiasse

- **Accelerazione** : $\vec{a}=-\vec{g}\cdot\hat{j}$  
- **Componenti vettore velocità** : $\begin{cases}V_{x0}=V_0\cos(\theta_0)\\V_{y0}=V_0\sin(\theta_0)\end{cases}$
- **Componenti vettore velocità istantanea** : $\begin{cases}V_x(t)=V_0\cos(\theta_0)(costante)\\V_y(t)=V_0\sin(\theta_0)-gt\end{cases}$
- **Componenti vettore posizione in funzione di t** : $\begin{cases}x(t)=V_0\cos(\theta_0)t\\y(t)=V_0\sin(\theta_0)t-\frac{1}{2}gt^2\end{cases}$
- **Gittata** : Distanza orizzontale tra la pos di partenza e l'istante in cui il corpo ritorna $y=0$; formula : $D=\frac{V_0^2}{g}\sin(2\theta_0)$, assume val max quando $\theta_0=45^{\circ}$, oppure $D=x(\tilde{t})=V_{x0}\tilde{t}$
	- **Tempo di salita del corpo** : $\tilde{t}=V_{x0}-g\tilde{t}$ e ricavi $\tilde{t}$
	- **Tempo corpo va da** terra (pos. $A$) e ritorna a terra (pos. $B$) è il doppio del tempo trovato sopra, poichè simmetrico
- **Formula che lega velocità e posizione** : $(V_x(t))^2=V_{x0}^2+2a_x(x(t)-x_0)$, vale anche per $y(t)$
## Moto circolare uniforme
Traiettoria circolare

- **Modulo velocità istantanea costante** : $\left|\vec{V}(t)\right|=V_0$
- $\vec{a}$ e $\vec{V}$ direzioni perpendicolari
- **Angolo** : $\Delta\theta$ tra $\vec{r_1},\vec{r_2}=\vec{V_1},\vec{V_2}$
- **Variazione vettore velocità** : $\left|\Delta\vec{V}\right|=2V_0\sin(\frac{\Delta\theta}{2})$
- **Accelerazione vettoriale media** : $\vec{a}_{med}=\frac{\Delta\vec{V}}{\Delta t}$
- **Accelerazione vettoriale istantanea** : $\vec{a}=\lim_{\Delta t\to0}\frac{\Delta\vec{V}}{\Delta t}$
	- Usando il raggio vale $a=\left|\vec{a}\right|=\frac{V_0^2}{R},R=$raggio
	- $\vec{a}$ diretta verso il centro ad ogni istante $t$, quindi si chiama **acc. centripeta**
- **Periodo** : Istante necessario a completare un giro completo, $T=\frac{2\pi r}{V_0}$
- **Frequenza** : Numero di giri in un secondo, $f=\frac{1}{T}=\frac{V}{2\pi r}$, misura "Hertz"
- **Velocità angolare** : Angolo per unità di tempo, $\omega=\frac{2\pi}{T}=2\pi f$ , miusra rad/s
- **Legame tra** $V_0,\omega$ : $V_0=\omega^2R$ 
- **Componenti acc. vettoriale istantanea** : $\begin{cases}\vec{a_r}=\text{componente radiale = acc. radiale}\implies\vec{a_r}=\frac{V^2}{R},R=\text{Raggio della circonferenza osculatrice}\\\vec{a_t}=\text{componente tangenziale = acc. tangenziale}\implies\vec{a_r}=\left|\frac{\Delta\left|\vec{V}\right|}{\Delta t}\right|\end{cases}$
# 2 Dinamica

## Leggi del moto
Ricorda, la proiezione di una forza su asse x è $F\cos(\theta)$ e proiezione forza su asse y è $F\sin(\theta)$, occhio ai segni. Se si tratta di piano inclinato la situazione si ribalta.
Se velocità costante, allora accelerazione nulla

- **Forza risultante** : Somma delle forze agenti sul corpo, si miusura in $N(Newton)$
	- **Prima legge della dinamica** : Se la forza risultante su un corpo è nulla $\implies$ il corpo ha Accelerazione nulla
	- **Seconda legge dinamica** : $m\vec{a}=\sum\limits_{k=1}^n\vec{F}_k,\vec{F}_k=$ forze agenti sul corpo
- **Forza gravitazionale** : $\vec{Fg}$ peso, risulta $\vec{Fg}=m\vec{g}$
	- **Terza legge dinamica** : Dati 2 corpi A e B tra loro interaggenti, la forza esercitata da A su B è uguale alla forza esercitata da B su A, con stessa direzione ma verso opposto, $\vec{F}_{AB}=-\vec{F}_{BA}$
- **Corpo fermo su piano orizzontale** : La forza peso $mg$ e la reazione vincolare $N$ si annullano a vicenda, per la 2 legge din vale $\vec{N}+m\vec{g}=0\implies\vec{N}=m\vec{g}$
- **Situazione di equilibrio** : La somma delle forze agenti deve essere nulla (vale anche per attrito)
- Se chiede modulo max forza tale che corpo rimane attaccato a sup.piana, deve valere che la reazione vincolare $\geq0$, quindi prima fai calcoli per trovare $N$ e poi metti condizione $\geq0$ 
### Applicazioni leggi del moto
Forza attrito statico/dinamico sono forze che si oppongono al moto

- **Forza attrito dinamico** : Resistenza al moto, vale $F_d=\mu_dN$, con $\mu_d=$ coeff. di attrito dinamico
	- **Lavoro forza attrito dinamico** : $F_d*\Delta\vec{s},\Delta\vec{s}=$ spostamento del corpo
- **Forza attrito statico** : Resistenza al moto quando corpo rimane fermo, risulta $F_s\leq\mu_sN$, con $\mu_s=$ coeff. di attrito statico
- Per trovare modulo max di $F_d$ = derivata di $F_d$ trovata durante i calcoli, posta $\geq0$, da li esce $\tan(\theta)\leq$ qualcosa e poi $\theta\leq\arctan(\theta)$, poi sostituisci in $F_d$ il $\theta_1=\arctan(\theta)$
- Per calcolare $\mu_s$ minimo basta svolgere i calcoli e risolvere l'eq. $F_S\leq\mu_sN$, con $F_s$ ottenuta tramite calcoli
## Dinamica del moto circolare uniforme
Velocità $\vec{V}$ e acc. centripeta $\vec{a_c}$ costanti e $\vec{a_c}\perp\vec{V}$ Perpendicolari

- **Tensione cavo** : $T=m\left|\vec{a_c}\right|=m\frac{V^2}{l}$
## Moto viscoso
Il mezzo in cui si muove il corpo si oppone al moto del corpo, esercitando forza frenante

- **Forza frenante con modulo proporzionale alla velocità del corpo** : $\vec{F}_r=-b\vec{V}$
	- **Velocità con cond. iniz.** $V_x(0)=0$ : $V_x(t)'=g-\frac{b}{m}V_x(t)$, con $a_x(t)=V_x(t)'$
	- **Velocità limite** : $V_l=\frac{mg}{b}$, quindi
	- $V_x(t)=\frac{mg}{b}(1-e^{-\frac{bt}{m}})=V_l(1-e^{-\frac{t}{\tau}})$
- **Forza frenante con modulo proporzionale al quadrato della velocità del corpo** : $\vec{F}_r=\frac{1}{2}D\rho AV^2$, con $D=$ coeff. di attrito viscoso, $\rho=$ densità aria, $A=$ sez. trasversale perpendicolare alla velocità
	- **Velocità con cond. iniz.** $V_x(0)=0$ : $V_x(t)'=g-\frac{D\rho A}{2m}(V_x(t))^2$, con $a_x(t)=V_x(t)'$
	- **Velocità limite** : $V_l=\sqrt{\frac{2mg}{D\rho A}}$
## Energia e Lavoro

- **Lavoro di una forza _costante_** : $W=\left|\vec{F}\right|\cos(\theta)\left|\Delta\vec{r}\right|$, con $\left|\Delta\vec{r}\right|$ = spostamento del corpo ($x_f-x_i$)
	- **Misura** : $10^{-7}J(Joule)$
	- **Lavoro forza peso** : $W_p=-mg(y_f-y_i)=mgy_i-mgy_f$
- **Una forza applicata al corpo non compie lavoro se** :
	- Corpo fermo
	- Se $\left|\Delta\vec{r}\right|$ perpendicolare a $\vec{F}$ (es. se un corpo si sposta su una sup, la reazione vincolare $\vec{N}$ risulta perpendicolare al vettore ist. del corpo velocità ad ogni istante, quindi $\vec{N}$ non compie lavoro)
- **Lavoro di una forza _variabile_** : $W(\vec{r_0}\to\vec{r_1})=\int_{t_0}^{t_1}[\vec{F}(t)\vec{V}(t)]\,dt$, indica lavoro svolto da forza agente sul corpo affinchè si sposti da pos. $r_0(ist.\space t_0)$ a $r_1(ist.\space t_1)$
### Legge di Hooke e Forza elastica
Corpo poggiato su piano orizz. con attrito trascurabile. Il corpo è attaccato a un'estremità di una mollta, l'altra estremità della molla att. a parete

- **Legge di Hooke** : $F_x=-k(x-l)$, con $l=$ lunghezza a riposo della molla, $k=$ costante elastica misura $\frac{N}{m}$
- La forza elastica è **forza di richiamo**
- Nei calcoli si mette l'origine dell'asse x dove la molla sta a riposo, cosi vale $F_x=-kx$
- **Lavoro forza elastica** : $W_{el}=(x_i\to x_f)=\frac{1}{2}k(x_i^2-x_f^2)$
### Energia Cinetica e TH Energia Cinetica

- **Energia cinetica** : $K=\frac{1}{2}m\left|V\right|^2$ misura in $J(Joule)$
- **TH energia cinetica** : Il lavoro della risultante delle forze agenti sul corpo è uguale alla variazione di en. cinetica, $W_{tot}=K_f-K_i$
## Potenza
$\Delta W$ lavoro costante da una forza nell'intervallo $\Delta t$

- **Potenza media** : $\mathbb P=\frac{\Delta W}{\Delta t}$
- **Potenza istantanea** : $\mathbb P(t)=\vec{F}(t)\vec{V}(t)$, misura in $W(Watt)$
- **Energia potenziale gravitazionale** : $U_p(y)=mgy$, quindi $W_p=-\Delta U_p$
- **Energia meccanica con forza peso** : $E_m=\frac{1}{2}m\left|\vec{V}\right|^2+mgy=K+U_p$
	- Sotto l'azione della sola forza peso, **l'energia meccanica si conserva**
- **Energia potenziale elastica** : $U_{el}=-\frac{1}{2}kx^2$
- **Energia meccanica con forza elastica** : $E_m=\frac{1}{2}m\left|\vec{V}\right|^2+\frac{1}{2}kx^2=K+U_{el}$
	- Sotto l'azione della sola forza elastica, **l'energia meccanica si conserva**
- **Forze conservative** : Forza peso, Forza Elastica
- **Equilibrio stabile sotto forza cons.** : punto di *minimo relativo* per la funzione di energia potenziale
- **Equilibrio stabile sotto forza non cons.** : punto di *massimo relativo* per la funzione di energia potenziale
- **Equilibrio indifferente** : Funzione energia potenziale costante per un certo tratto
# 3 Quantità di moto

- **Quantità di moto** : $\vec{\rho}(t)=m\vec{V}(t)$
- **La somma delle quantità di moto di un sistema isolato si conserva**
- **Espressioe generale della 2 legge dinamica** : $\vec{F}_{ris}=(\vec{\rho}(t))'$
- **Legge di conservazione della quantità di moto** : $\vec{\rho_{tot}}(t)=\vec{\rho_1}(t)+\vec{\rho_2}(t)$ costante
	- A $N$ corpi arbitrari vale : $\sum\limits_{i=1}^N\vec{\rho_i}(t)$
- **Conservazione quantità di moto** : $\rho_{tot,f,x}=\rho_{tot,i,x}$ implica che c.d.m si muove di moto rettilineo unif.
## Impulsi e quantità di moto

- **Variazione della quantità di moto di un corpo sottoposto alla forza** $\vec{F}_{ris}$ : $\Delta\vec{\rho}(t_i\to t_f)=\int_{t_i}^{t_f}\vec{F}_{ris}(t)\,dt$
- **Impulso** : Quantità $\vec{I}=\Delta\vec{\rho}(t_i\to t_f)$ oppure $I=\vec{\rho}_f-\vec{\rho}_i$
- **Forza media** : $\vec{F}_{med}=\frac{\Delta\vec{\rho}}{\Delta t}$ 
## Urti unidimensionali

- **Urto** : Interazione tra due corpi che avviene in un intervallo breve di tempo
	- **Se il sistema è isolato, la quantità di moto totale si conserva**
	- **Urto anelastico** : Quando *energia cinetica totale* non si conserva
		- **totalmente anelastico** quando i due corpi rimangono attaccati
	- **Urto elastico** : Quando *energia cinetica totale* si conserva
- **Durante gli urti, se il sistema non è isolato, la quantità di moto totale non si conserva, in quanto potrebbero agire forze estrerne al sistema**
- **Velocità finale urti totalmente anelastici** : $V_{fx}=(m_1V_{1,i,x}+m_2V_{2,i,x})/(m_1+m_2)$
- **Velocità finale urti elastici** : $\begin{cases}V_{1,f,x}=(\frac{m_1-m_2}{m_1+m_2})V_{1,i,x}+(\frac{2m_2}{m_1+m_2})V_{2,i,x}\\V_{2,f,x}=(\frac{2m_1}{m_1+m_2})V_{1,i,x}+(\frac{m_2-m_1}{m_1+m_2})V_{2,i,x}\end{cases}$
	- **Casi generali**
		- $m_1=m_2$, vale $\begin{cases}V_{1,f,x}=V_{2,i,x}\\V_{2,f,x}=V_{1,i,x}\end{cases}$
		- $V_{2,i,x}=0$ vale $\begin{cases}V_{1,f,x}=(\frac{m_1-m_2}{m_1+m_2})V_{1,i,x}\\V_{2,f,x}=(\frac{2m_1}{m_1+m_2})V_{1,i,x}\end{cases}$
## Urti bidimensionali
- **Legge di conservazione della quantità di moto** : $\vec{\rho}_{1f}+\vec{\rho}_{2f}=\vec{\rho}_{1i}+\vec{\rho}_{2i}$
- **Caso in cui corpo 1 urta corpo 2, inizialmente fermo** : $\begin{cases}\rho_{1,f,x}+\rho_{2,f,x}=\rho_{1,i,x}\\\rho_{1,f,y}+\rho_{2,f,y}=\rho_{1,i,y}\end{cases}$
	- $\begin{cases}\vec{V}_{1f}=V_{1f}\cos(\theta)\tilde{i}+V_{1f}\sin(\theta)\tilde{j}\\\vec{V}_{2f}=V_{2f}\cos(\phi)\tilde{i}+V_{2f}\sin(\phi)\tilde{j}\end{cases}$
- **Legge di conservazione della quantità di moto** : $\begin{cases}m_1V_{1f}\cos(\theta)+m_2V_{2f}\cos(\phi)=m_1V_{1,i}\\m_1V_{1f}\sin(\theta)+m_2V_{2f}\sin(\phi)=0\end{cases}$
	- Se l'urto è elastico bisogna aggiungere la cond. $E_{tot,f}=E_{tot,i}$
## Centro di massa di un sistema
- **Velocità centro di massa** : $\vec{V}_{cm}(t)=\frac{\vec{P}_{tot}(t)}{M_{tot}}$, con $\vec{P}_{tot}$ = quantità di moto tot. , $M_{tot}$ = massa totale
	- Andamento temporale velocità c.d.m = $V_{cm}(t)=V_0+a_xt$
- Se il sistema è isolato o la risultante è nulla, risulta $\vec{P}_{tot}$ = costante e quindi $\vec{V}_{cm}(t)=$ costante
- **Accelerazione centro di massa** : $\vec{a}_{cm}(t)=\frac{1}{M_{tot}}\vec{F}_{e,tot}(t)$, con $\vec{F}_{e,tot}$ = F. agente esterna totale
	- Si **può trovare anche** usando la velocità angolare, così $a_{cm}=\omega^2\cdot r$, con $r=$ distanza tra perno e centro di massa, nella sbarra $r=\frac{L}{2}$
		- Uguale ad acc. centripeta nel moto circolare e rotatorio
- **Prima equazione cardinale della dinamica dei sistemi di punti materiali** : $(\vec{P}_{tot}(t))'=\vec{F}_{e,tot}$, e quindi $m\vec{a_{cm}}=\vec{F}_{e,tot}$
### Determinazione centro di massa
- **Posizione centro di massa di filo omogeneo** : $x_{cm}=\frac{L}{2}$ , con $L=$ lunghezza
### Energia pot. gravitazionale di un sistema di punti mat.
- **Energia potenziale gravitazionale** : $U_p=gM_{tot}z_{cm}$
- **Corpo solido vincolato** : la pos. di equilibrio stabile uguale a posizione in cui l'energia pot. risulta minima, quindi quando $z_{cm}$ minimo
### Energia cinetica e lavoro per sistema di punti mat.
- **Velocità relativa istantanea** : $\vec{V}_r(t)=\vec{V_1}(t)-\vec{V_2}(t)$
- **Energia cinetica totale** : $K_{tot}=\frac{1}{2}M_{tot}\left|\vec{V}_{cm}(t)\right|^2+\frac{1}{2}\frac{m_1m_2}{M_{tot}}\left|\vec{V}_{r}(t)\right|^2$
- **massa ridotta** : $\mu=\frac{m_1m_2}{M_{tot}}$
## Moto rotazionale
- conversione radianti gradi : $\theta(rad)=\frac{\pi}{180}\theta$ ed esce gradi
- **Spostamento angolare** : $\Delta\theta=\theta_f-\theta_i$ variazione di posizione angolare di un punto tra $t_i$ e $t_f$
- **Velocità angolare media** : $\omega_m=\frac{\Delta\theta}{\Delta t}$
- **Velocità angolare istantanea** : $\omega(t)=(\theta(t))'$
	- Se $\theta(t)$ cresce allora $\omega(t)\gt0\implies$ rotazione senso antiorario
	- Se $\theta(t)$ decresce allora $\omega(t)\lt0\implies$ rotazione senso orario
	- Andamento temporale velocità angolare = $\omega_{cm}(t)=\omega_0+a_xt$
- **Accelerazione angolare media** : $\alpha_m=\frac{\Delta\omega}{\Delta t}$
- **Accelerazione angolare istantanea** : $\alpha(t)=(\omega(t))'=(\theta(t))''$
	- **Per trovare acc angolare usare calcolo dei momenti rispetto al polo**, così risulta $I_z\alpha(t)=\tau_{tot}$ 
### Moto circolare e rotatorio con acc. costante
$\alpha(t)=\alpha$ costante
- **Velocità angolare** = $\omega(t)=\omega_0+\alpha t$
- **Legge oraria** : $\theta(t)+\theta_0+\omega_0 t+\frac{1}{2}\alpha t^2$
- **Relazione che lega velocià e acc.** : $(\omega(t))^2=\omega_0^2+2\alpha[\theta(t)-\theta_0]$
- **Quantità vettoriali nel moto circolatorio**
	- **Velocità tangenziale** : $V_t(t)=r\omega(t)$ , con $r$ = raggio circonferenza
	- **Acc. centripeta** : $\vec{a}_c=\frac{(V_t(t))^2}{r}$
	- **Acc. tangenziale** : $\vec{a}_t=(V_t(t))'$
### Energia cinetica rotazionale di un sistema rigido
- **Energia cinetica del punto i-esimo** : $K_i=\frac{1}{2}m_i\left|\vec{V_i}\right|^2=\frac{1}{2}m_i(r_i\omega)^2=\frac{1}{2}m_ir_i^2\omega^2$
- **Momento di inerzia** : $I_z=\sum\limits_{i=1}^N(m_ir_i)^2$
- **Energia cinetica di sistema rigido** : $K=\frac{1}{2}I_z\omega^2$
- **Momenti inerzia canonici** 
	- Anello o guscio cilindrico molto sottile : $I_z=MR^2$, $R=$ raggio
	- Corona circolare o guscio cilindrico non sottile : $I_z=\frac{1}{2}M(R_1^2+R_2^2)$
	- Cilindro pieno o disco : $I_z=\frac{1}{2}MR^2$ , se asse di rotazione passa per c.d.m
	- Sfera piena : $I_z=\frac{2}{5}MR^2$, asse di rotazione passante per centro della sfera
	- Guscio sferico sottile : $I_z=\frac{2}{3}MR^2$
	- Sbarra sottile, con asse di rotazione passante per perno fisso $I_z=\frac{1}{3}ML^2$
### Momento di una forza
- **Momento di una forza** $\vec{F}$ **rispetto al polo O** : $\vec{\tau}=\vec{R}\times\vec{F}$, con $\vec{R}$ vettore posizione, si misura in $Nm$
- **Modulo momento di una forza** $\vec{F}$ : $\left|\vec{\tau}\right|=\left|\vec{R}\times\vec{F}\right|=RF\sin(\phi)$
	- $\left|\vec{\tau}\right|=R(F\sin(\phi))=RF_t$
	- $\left|\vec{\tau}\right|=F(R\sin(\phi))=Fd$, con $d$ = *braccio* della forza $\vec{F}$
- **Se si sceglie il perno in cui avviene la rotazione come polo per il calcolo dei momenti, allora il momento delle forze esterne agenti sarà nullo**, allora il momento angolare si conserverà. Vale per aste che ruota
### Dinamica di un corpo rigido
Il momento totale delle forze applicate a un sistema rigido costituito da 2 punti mat. è uguale al momento risultante delle sole forze esterne agenti sui due punti materiali, rispetto al polo scelto
- **Momento totale** : $\tau_{z,tot}=I_z\alpha$, con $\alpha$ costante
### Equilibrio di un corpo solido
- **Condizioni necessarie per l'equilibrio** 
	- $\sum\limits_{i=1}^N\vec{F_{ie}}=0\implies\vec{V_{cm}}$ = costante, quindi se il sistema è inizialmente fermo vale $\vec{V}_{cm}=0$
	- $\sum\limits_{i=1}^N\vec{\tau_{ie}}=0$ momento rispetto a un polo qualsiasi nullo
### Lavoro e potenza nel moto rotazionale
- **Lavoro di corpo rigido che ruota attorno asse z** : $W_{tot}=\frac{1}{2}I_z\omega_f^2-\frac{1}{2}I_z\omega_i^2$
- **Lavoro totale di sistema con N corpi** : $\Delta W_{tot}=\tau_{tot,z}(t)\omega(t)\Delta t$
- **Potenza istantanea** : $\mathbb P=\tau_{tot,z}(t)\omega(t)$
### Momento angolare
- **Momento angolare/Momento della quantità di moto** : $\vec{L}(t)=\vec{R}(t)\times\vec{\rho}(t)$, misura in $kgm^2s^{-1}$ 
- **Seconda equazione cardinale della dinamica dei sistemi di N punti materiali** : $[\vec{L}(t)]'=\vec{\tau}_{e,tot}(t)$, con $\vec{\tau}_{e,tot}(t)$ = momento delle forze esterne agenti sul sistema
- **Corpo rigido con polo sull'asse di rotazione** : $L_{tot,z}=I_z\omega\implies[L_{tot,z}]'=I_z(\omega)'=I_z\alpha$
- **Teoremi di Konig**
	- 1. Momento angolare totale di un sistema di N punti : $\vec{L}_{tot}(t)=\vec{R}_{cm}(t)\times\vec{P}_{cm}(t)+\vec{L}_{tot}'(t)$
		- $\vec{L}_{tot}(t)'$ momento angolare totale rispetto al c.d.m
	- 2. Energia cinetica totale di un sistema di N punti materiali $K_{tot}=\frac{1}{2}M_{tot}\left|\vec{V}_{cm}\right|^2+K_{tot}'$
		- $K_{tot}'=\frac{1}{2}I_{z',cm}\omega^{'2}$ , con $I_{z',cm}$ = mom. di inerzia rispetto ad asse pass. per c.d.m
### Conservazione del momento angolare
La seconda equazione cardinale implica che se $\vec{\tau}_{e,tot}(t)=0$ allora il **momento angolare totale** del sistema resta costante, quindi si **conserva**
- **Conservazione momento angolare** : $L_{tot,z,f}=L_{tot,z,i}$
**In sistema isolato si conservano la quantità di moto totale e il momento angolare totale** 
- Sistema isolato rigido in rotazione attorno asse z : $L_{tot,z}=I_z\omega$ = costante
- Sistema isolato non rigido in rotazione attorno asse z : $L_{tot,z}(t)=I_z(t)\omega(t)$ = costante
### Moto di puro rotolamento di corpo rigido
Corpo rigido sferico che rotola senza strisciare su superficie piana
La condizione affinchè il corpo rigido rotoli senza strisciare è che la velocità istantanea del punto di contatto P tra il corpo e il piano sia nulla
- **Condizione di pure rotolamento** : $V_{cm}(t)=\omega(t)R$
- **Acc. nel moto** : $a_{cm}=\alpha(t)R\implies\alpha(t)=\frac{a_{cm}(t)}{R}$
- **Energia cinetica in questione (usando 2 TH Konig)** : $K(t)=\frac{1}{2}\left(M+\frac{I_z'}{R^2}\right)\left|\vec{V}_{cm}(t)\right|^2$, con $I_z'$ = mom. di inerzia del corpo rigido 
## Moto oscillatorio e onde
Consideriamo moto sotto l'effetto della forza elastica
- **Moto armonico semplice** : $[x(t)]''=-\frac{k}{m}x(t)$
	- posto $\omega^2=\frac{k}{m}$ si ottiene $[x(t)]''+\omega^2x(t)=0$, la cui soluzione è
		- $x(t)=A\cos(\omega t+\phi_0)$, con 
			- $A$ = **ampiezza**, valore massimo di $|x(t)|$ 
			- $\omega$ = **pulsazione/frequenza angolare** (nel caso di F. elastica $=\sqrt{\frac{k}{m}}$) 
			- $\phi_0$ = **costante di fase/fase iniziale**
			- $\phi(t)=\omega t+\phi_0$ = **fase del moto**
	- Nel caso di moto armonico sotto l'eff. di forza elastica vale : 
		- **Periodo** : $T=2\pi\sqrt{\frac{m}{k}}$
		- **Frequenza** : $f=\frac{1}{2\pi}\sqrt{\frac{k}{m}}$
- **Velocità istantanea** : $V_x(t)=-\omega A\sin(\omega t+\phi_0)$
- **Acc. istantanea** : $a_x(t)=-\omega^2 A\cos(\omega t+\phi_0)$
- **Condizioni iniziali del moto** : $x_0=x(t=0),V_{x0}=V_x(t=0)$
	- $x_0=A\cos(\phi_0)$
	- $V_{x0}=-\omega A\sin(\phi_0)$
		- $V_x(t)=\omega A\cos(\omega t+\phi_0+\frac{\pi}{2})$
		- $a_x(t)=\omega^2 A\cos(\omega t+\phi_0+\pi)$
- **Pendolo Semplice** : 
	- Verso positivo dell'asse tangenziale è in senso antiorario
	- Verso positivo dell'asse radiale è verso il centro della traiettoria circolare
	- **Equazione del moto** : $[\theta(t)]''=\frac{g}{L}\sin([\theta(t)])=0$ $(**)$
	- **Energia potenziale** : $U(\theta)=-mgL\sin(\theta)$
- **Piccole oscillazioni** : piccolo intervallo $\Delta\theta(t)$ attorno al punto di equilibrio stabile, $sen[\theta(t)]\approx\theta(t)$ 
	- $(**)$ diventa $\theta(t)=\theta_{max}\cos(\omega t+\phi_0)\implies\omega=\sqrt{\frac{g}{L}}$ 
	- **Periodo piccole oscillazioni** : $T=2\pi\sqrt{\frac{L}{g}}$
- **Pendolo Fisico** 
	- **Velocità angolare nelle piccole oscillazioni** : $\omega=\sqrt{\frac{Mgd}{I_z}}$
	- **Periodo angolare nelle piccole oscillazioni** : $T=2\pi\sqrt{\frac{I_z}{Mgd}}$
# 4 Elettricità e Forza Elettrica
Cariche elettriche con lo stesso segno si respingono, con segno diverso si attraggono
- **Principio di conservazione della carica elettrica** : In un sistema isolato, la carica elettrica totale si conserva
## Isolanti e Conduttori
- **Conduzione elettrica** : Una carica elettrica può muoversi all'internon di un corpo
- **Conduttori** : In questi materiali alcuni elettroni sono liberi di muoversi nel corpo
- **Isolanti** : In questi materiali tutti gli elettroni sono legati agli atomi e non possono muoversi liberamente
## Legge di Coulomb
- **Legge di Coulomb** : $\left|\vec{F_e}\right|=F_e=K_e\frac{\left|q_1\right|\left|q_2\right|}{r^2}$
	- $F_e$ = Forza elettrica
	- $\left|q_i\right|$ valore assoluto carica elettrica i-esima
	- $r$ distanza tra due cariche
	- $K_e$ = **costante di Coulomb**, si misura $C(Coulomb)$ e vale $8.9876\cdot10^9\frac{Nm^2}{C^2}$
		- Vale anche $K_e=\frac{1}{4\pi\varepsilon_0}$, con $\varepsilon_0$ = **costante dielettrica del vuoto**
			- vale $\varepsilon_0=8.854\cdot10^{-12}\frac{C^2}{Nm^2}$
- **Carica elettrica dell'elettrone** : $q_e=-e=-1.60218\cdot10^{-19}C$
- **Osservazione** : Per dire se una forza elettrica è repulsiva/attrattiva, basta vedere il segno delle cariche elettriche. Se hanno segno uguale allora repulsiva, altrimenti attrattiva
- Se la forza elettrica è l'unica forza agente, **l'energia meccanica si conserva**, quindi $E_{mf}=E_{mi}$
## Campi Elettrici
- **Campo elettrico (vettore)** : $\vec{E}=\frac{\vec{F_e}}{q_0}$, si misura in $N/C$, con $q_0$ = carica di prova
- Con campo elettrico noto, si scrive $F_e=q\vec{E}$
- **Campo elettrico (vettore) per cariche puntiformi** : $\vec{E}=\frac{\vec{F_e}}{q_0}=K_e\frac{q}{r^2}$
	- se $q>0$ il campo elettrico è diretto verso $q$ con verso uscente (verso dx)
	- se $q<0$ il campo elettrico è diretto verso $q$ con verso entrante (verso sx)
- **Campo elettrico (vettore) per cariche puntiformi nel punto P** : $\vec{E}_P=K_e\sum\limits_{i=1}^N\frac{q_i}{r_i^2}$
- il campo elettrico non è definito nella posizione in cui si trova la sorgente puntiforme
### Campo Elettrico generato da distribuzione continua di carica
- **Distribuzione continua** : quando la distanza tra due cariche sorgente di una distribuzione di carica è molto piccola
	- La distribuzione viene divisa in intervalli $\Delta q$, e il campo elettrico è $\vec{E}=K_e\frac{\Delta q_i}{r_i^2}$
- **Densità di carica** : quando la carica è distribuita lungo linea, superficie o volume
	- $\lambda=\frac{Q}{l}$, se carica $Q$ è distribuita uniformemente lungo tratto di lunghezza l (**densità lineare**)
	- $\sigma=\frac{Q}{A}$, se carica $Q$ è distribuita uniformemente lungo superficie di area A (**densità superficiale**)
	- $\rho=\frac{Q}{V}$, se carica $Q$ è distribuita uniformemente in volume V (**densità di volume**)
## Moto di particelle cariche in campo elettrico uniforma
- se $q\vec{E}$ è la risultante delle forze agenti sulle particelle, vale $m\vec{a}=q\vec{E}$, quindi
- **Accelerazione** : $\vec{a}=\frac{q\vec{E}}{m}$
	- Se $\vec{E}$ costante anche $\vec{a}$ è costante
## Flusso elettrico
- **Flusso elettrico** : 
	- Se il campo attraversa perpendicolarmente una superficie A, vale $\left|\Phi_E\right|=\left|\vec{E}\right|A$ 
	- Se la superficie A *non* è perpendicolare al campo, vale $\left|\Phi_E\right|=\left|\vec{E}\right|A\cos(\theta)$
		- $\theta$ è l'angolo tra il campo e la direzione normale, se $\theta=90^{\circ}$ allora il flusso è nullo
	- Se la superficie è curva, vale $\Phi_E=\int_{\text{superficie}}\vec{E}\,d\vec{A}$ 
	- Se la superficie è chiusa vale $\Phi_E=\oint\vec{E}\,d\vec{A}=\oint E_ndA$ 
### Teorema di Gauss
Carica puntiforme positiva q al centro di una sfera di raggio r genera campo elettrico con linee radiali e verso uscente
Il flusso elettrico è $\Phi_E=\left|\vec{E}\right|A_{\text{superficie}}$
- **Flusso elettrico dentro la sfera** : $\Phi_E=\frac{q}{\varepsilon_0}$
	- Il flusso elettrico totale attraverso la superficie chiusa che non circonda una carica elettrina netta è nullo
- **Teorema di Guass** : Il flusso totale del campo attraverso una qualunque superficie chiusa è espresso dalla legge : $\Phi_E=\oint\vec{E}d\vec{A}=\frac{q_{in}}{\varepsilon_0}$, con $q_{in}$ = carica totale interna alla superficie chiusa
#### Applicazioni th gauss
- A. Sfera solida con raggio $a$, densità $\rho$ e carica tot. $Q$
	- **Campo elettrico in un punto esterno a sfera** : $\left|\vec{E}\right|=K_e\frac{Q}{r^2}$
	- **Campo elettrico in un punto interno a sfera** : $|\vec{E}|=K_e\frac{Q}{a^3}r$
- B. Campo elettrico a distanza $r$ da filo di lunghezza inf. e carica $\lambda$ costante
	- **Campo elettrico** : $|\vec{E}|=2K_e\frac{\lambda}{r}$
- C. campo elettrico generato da piano con densità $\sigma$
	- **Campo elettrico** : $|\vec{E}|=\frac{\sigma}{2\varepsilon_0}$
### Conduttori in equilibrio elettrostatico
- **Equilibrio elettrostatico** : Non c'è moto di cariche nel conduttore
- 4 condizioni
	- Campo elettrico interno nullo
	- Eventuali cariche aggiunte vanno a localizzarsi su superficie esterna
	- Campo elet. esterno diretto perpendicolarmente alla superficie del condensatore
	- Densità di carica maggiore nei punti in cui il raggio di curvatura della superficie è minore
### Potenziale elettrico
**La forza elettrica è conservativa**
- **Potenziale elettrico** : $V=\frac{U}{q}$
- **Differenza di potenziale** : $V_f-V_i=-q\int_{t_i}^{t_f}[\vec{E}(t)\vec{V}(t)]dt$
	- Unità di misura diff. di potenziale e potenziale elet. $V(Volt)=\frac{J}{C}$
	- **Elettronvolt** : $eV=1.602\cdot10^{-19}J$
#### Diff. di potenziale in campo elettrico uniforme
- **Variazione differenza di potenziale** : $\Delta V=V_B-V_A=-Ed$, con $d$ = distanza tra i punti $A$ e $B$
- **Variazione energia potenziale** : $\Delta U=q\Delta V=-qEd$
- 2 osservazioni
	- la forza elettrica compie lavoro positivo su carica positiva quando questa si muove nel verso del campo elettrico
	- la forza elettrica compie lavoro positivo su carica negativa quando la carica si muove nel verso opposto rispetto a quello del campo elettrico
#### Potenziale elettrico ed ener. poten. elettrica di cariche puntiformi
- **Energia potenziale coppia di particelle con cariche** $q,q_0$ : $U(r)=K_e\frac{qq_0}{r}+costante$, con $r$ = posizione di $q$
	- Energia potenziale negativa se le cariche hanno segno negativo, altrimenti è positiva
- **Potenziale elettrico associato a una carica puntiforme** $q$ : $V(r)=K_e\frac{q}{r}+costante$, con $r$ = distanza tra $q$ e $q_0$, quindi $(q_0-q)$
- **Potenziale elettrico totale in un dato punto** $P$ : $V=K_e\sum\limits_i\frac{q_i}{r_i}$, con $r_i$ distanza tra $q_i$ e $P$
- **Energia potenziale di sistema con due cariche** : $U_{12}=K_e\frac{q_1q_2}{r_{12}}$, con $r_{12}=|\vec{r_1}-\vec{r_2}|$
- **Condizione di annullamento di un campo elettrico** : Energia potenziale prima carica+energia potenziale seconda carica=$0$ 
### Capacità
- **Condensatore** : sistema di 2 conduttori in cui una carica positiva $Q$ è stata trasferita da uno all'altro
	- **Quando corrente a regime, il ramo del condesatore si comporta come ramo aperto, quindi non passa corrente**
- **Capacità** : $\frac{Q}{V}$, indica quanta carica può essere accumulata nel condensatore quando viene applicata una diff. di potenziale $V$, unitò di misura $F(Farad)=1\frac{C}{V}$
	- Condensatore sferico isolato : $\frac{Q}{V}=4\pi\varepsilon_0R$
- 2 tipi di condensatori
	- **Condensatore piano** : 2 piastre conduttrici parallele aventi stessa area $A$ a distanza $d$ tra loro
		- Densità : $|\sigma|=\frac{Q}{A}$
		- Campo elettrico : $|\vec{E}|=\frac{Q}{\varepsilon_0A}$
		- Diff di pot. : $V=\frac{Qd}{\varepsilon_0A}$
		- **Capacità** $C=\frac{\varepsilon_0A}{d}$
	-  **Condensatore cilindrico** : raggio $a$
		- Diff di pot.  : $V=\frac{2K_eQ}{l}\log(\frac{b}{a})$
		- Capacità : $C=\frac{2\pi\varepsilon_0l}{\log(\frac{b}{a})}$
- 2 tipi di collegamento
	- A. **Condensatori in parallelo**
		- **Diff. di potenziale (tensione)** : Potenziale polo positivo
			- Se due condensatori in parallelo, la diff. di potenziale sarà la stessa, ad es $\frac{Q_1}{C}+\frac{Q_2}{C}$
		- **Carica elettrica totale** : $Q_{tot}=V(C_1+C_2)$
		- Con un solo condensatore vale $C_{eq}=C_1+C_2$
	- B. **Condensatori in serie**
		- **Tensione** : $V=\frac{Q}{C_1}+\frac{Q}{C_2}$
		- Con un solo condensatore $\frac{1}{C_{eq}}=\frac{1}{C_{1}}+\frac{1}{C_{2}}$
- Carica di due consensatori dopo connessione in parallelo:
	- La carica totale sulla coppia di armature pos. deve essere uguale alla carica totale del sistema prima della connessione, in quanto le due armature costituiscono un unico sistema di conduttori
		- $Q_1+Q_2=2Q$, con $Q$ carica iniziale prima conn 
### Energia accumulata in un condensatore carico
- **Energia accumulata (aka Energia potenziale elettrostatica)** : $U=\frac{Q^2}{2C}=\frac{1}{2}CV^2$
	- Con condensatore pieno vale $C=\varepsilon_0^{A/d}$, quindi l'energia diventa $U=\frac{1}{2}\varepsilon_0(Ad)E^2$
## Corrente elettrica e circuiti
- **Corrente elettrica** : Rapidità con cui la carica elettrica fluisce attraverso la superficie considerata
- **Corrente media** : $I_{med}=\frac{\Delta Q}{\Delta t}$
- **Corrente istantanea** : $I(t)=[Q(t)]'$, con
	- $Q(t)$ = quantità di carica elettrica che ha attraversato la superficie tra un istante fissato e istante $t$
	- Unità di misura corrente $A(Ampere)=1C/s$
	- Il verso positivo della corrente è quello in cui fluisce la carica positiva, a prescindere dal segno delle cariche che sono in moto
- **Portatori di carica** : Costituenti mobili che contribuiscono alla corrente elettrica
- **Velocità di deriva** : $V_d$ = velocità media con cui i portat. di carica si muovono lungo direzione parallela all'asta del cono cilindrico
- **Corrente media nuovo** : $I_{med}=nqAV_d$, con
	- $n$ = numero di port. di carica
	- $q$ = carica per unità di volume
	- $A$ sezione trasversale
- **Densità di corrente** : $J=\frac{I}{A}=nqV_d$, misura in $A/m^2$
	- $V_d=\frac{I}{Anq}$
## Legge di Ohm

- **Legge di Ohm** : $\Delta V=RI$, unità di misura $1\Omega$ con $R$ resistenza
- **Resistenza di un filo conduttore ohmico con lunghezza l e sezione A** : $R=\rho\frac{l}{A}$, con $\rho$ = resistività
### Energia e potenza nei circuiti
- **Potenza** : $P(t)=I(t)\Delta V$
	- Nel caso di resistore, la potenza è $P=I^2R=\frac{(\Delta V)^2}{R}$
- **Sorgenti di f.e.m** : Dispositivo che mantiene una diff. di potenziale costante tra due punti
	- simbolo $\mathcal E = \varepsilon(grande)$ misura in $V(Volt)$
		- ai capi della batteria vale $\mathcal E=rI=\Delta V$
		- in assenza di collegamento esterno, ovvero in assenza del ramo con il resistore $R$ vale $\mathcal E=\Delta V$
	- **Per misurare diff. di potenziale ai capi dei resistori basta fare così**
		- scegli un nodo, es. $P$, poi vedi se resistore in parallelo o serie
			- se resistore è in serie calcoli $V_p(R_2)=\text{sorgente f.e.m}-R_1I$, con $R_1=$ resistore **prima** di $P$, $R_2$ il resistore di cui si vuole calcolare la diff. di potenziale e $I$=corrente passante per resistore
				- Da qui ti puoi calcolare la corrente, basta fare formula inversa
				- Se c'è un solo resistore, ovviamente $V_p=\mathcal E-RI$ 
			- se il resistore che vedi è in parallelo allora sarà $V_p=rI$ 
				- Stessa cosa, formula inversa per corrente
- **Resistenza di carico** : $RI=\mathcal E-rI$
	- $(R+r)I=\mathcal E$
		- $I=\frac{\mathcal E}{R+r}$
- **Ampiezza oscillazioni f.e.m** = $E=|\mathcal E|_{max}$
### Resistori in serie e parallelo
- Serie
	- Differenza di potenziale = $\Delta V=I(R_1+R_2)$
- Parallelo
	- $I=(\frac{1}{R_1}+\frac{1}{R_2})\Delta V$ 
### Leggi di Kirchhoff
- **Ramo** : Tratto singolo di un circuito che contiene almeno un nodo
- **Nodo** : Punto di circuito in cui confluiscono più rami
- **Maglia** : Percorso chiuso in circuto
- **Prima legge (regola dei nodi)** : In ogni nodo del circuito, la somma algebrica delle correnti deve essere nulla
- **Seconda legge (regola delle maglie)** : La somma algebrica delle diff. di potenziale ai capi di ciascun elemento della maglia deve essere nulla
### Circuiti RC
- **Circuito RC** : Contiene almeno un collegamento in serie di un resistore e di un condensatore
- **Carica di un condensatore** : 
	- Corrente $I(0)=\frac{\mathcal E}{R}$
	- Carica : $Q_{max}=C\mathcal E$
	- $q(t)=C\mathcal E[1-e^{-(t/RC)}]$
	- $I(t)=\frac{\mathcal E}{R}e^{-(t/RC)}$
- **Scarica di un condensatore**
	- $q(t)=Qe^{-(t/RC)}$
		- **Costante di tempo di scarica** : $\tau=RC$
	- $I(t)=-\frac{Q}{RC}e^{-(t/RC)}$

# 5 Campo Magnetico 
- **Campo magnetico** : Vettore $\vec{B}$
- **Forza magnetica** : $\vec{F}_b$ agente su particella, vale $\vec{F}_b=q\vec{V}\times\vec{B}$ si misura in $T(Tesla)$
	- modulo : $F_b=|q|VB\sin(\theta)$
## Moto particella carica in campo magnetico uniforme
- **raggio traiettoria** : $r=\frac{mV}{|q|B}$
- **Velocità angolare ciclotrone** : $\omega=\frac{|q|B}{m}$
- **Periodo** : $T=\frac{2\pi m}{|q|B}$
### Applicazioni moto particelle
- **Forza di Lorentz** : $\vec{F}=q\vec{E}+q\vec{V}\times\vec{B}$
### Forza magnetica su conduttore percorso da corrente
- **Forza magnetica eser. su tratta di filo rett. in campo magnetico** : $\vec{F}_b=I\vec{L}\times\vec{B}$
- La forza magnetica totale agente su generico circuito chiuso percorso da corrente e posto in campo magnetico unif. è nulla
### Momento delle forze agenti su spira in campo magnetico
- **Momento forza magnetica** : $\tau_z^{*}=IAB$ , con $A=ab$
	- Se $\vec{B}$ è perpendicolare ai lati verticali, vale $\tau_z=IAB\sin(\theta)$
- **Momento di dipolo magnetico** : $\vec{\mu}=I\vec{A}$
- **Energia potenziale di dipolo magnetico** : $U=-\vec{\mu}\vec{B}$
### Legge di Biot-Savart
- **Legge di Biot-Savart** : $\Delta\vec{B}=K_mI(\frac{\Delta\vec{s}\times\tilde{r}}{r^2})$
	- $K_m=\frac{\mu_0}{4\pi}$
		- $\mu_0=4\pi\cdot10^{-7}$, misura in $\frac{Tm}{A}$ 
	- Se filo è rettilineo e molto lungo vale $B=\frac{\mu_0I}{2\pi r}$
### Teorema di Ampere
- **TH Ampere** : $\oint\vec{B}d\vec{s}=\mu_0I$
### Legge di Faraday-Neumann
sbarra metallica in circuito che scende raggiungerà vel. limite quando la forza magnetica in seguito a passaggio di corrente equilibrerà la forza peso del corpo

- **Flusso magnetico(attraverso superficie nello spazio)** : $\Phi_B=\oint\vec{B}d\vec{A}$ misura in $Wb(Weben)$
	- Se superficie è spira allora $\vec{A}=\pi r^2$
- **Legge di Gauss per campo magnetico(flusso attraverso superficie chiusa)** : $\oint\vec{B}d\vec{A}=0$
- **Legge di Faraday-Neumann per circ. semplice** : $\mathcal E=-[\Phi_B(t)]'$
	- Serve per f.e.m indotta
- **Legge di Faraday-Neumann per circ. bobina con N spine** : $\mathcal E=-N[\Phi_B(t)]'$
	- Anche questo per f.e.m indotta
### Forza elettromotrice dinamica
- **f.e.m** : Forza indotta in un condensatore che si sta muovendo in campo $\vec{B}$
- $\Delta V=Blv$
- **Equazione flusso magnetico concatenato a circuito** : $\mathcal E=-[\Phi_B(t)]'=-Blv\implies I=\frac{Blv}{R}$
### Generatore di corrente alternata
- $\mathcal E=-N[\Phi_B(t)]'=NBA\omega\sin(\omega t)$
### Legge di Lentz
- **Enunciato semplice** : La f.e.m indotta ha un segno tale da produrre un flusso magnetico indotto tale da opporsi alla variazione di flusso magnetico che l'ha provocato
	- La direzione del campo mangetico te la dice il prof.
	- **Campo magnetico uscente** dal piano (verso di te):
	    - Se il flusso uscente **aumenta**, la corrente indotta circola in **senso orario** per opporsi a questo aumento (creando un campo opposto, verso il piano).
	    - Se il flusso uscente **diminuisce**, la corrente indotta circola in **senso antiorario** per "sostenere" il flusso uscente.
	- **Campo magnetico entrante** nel piano (verso il foglio):
	    - Se il flusso entrante **aumenta**, la corrente indotta circola in **senso antiorario** per opporsi a questo aumento (creando un campo opposto, uscente).
	    - Se il flusso entrante **diminuisce**, la corrente indotta circola in **senso orario** per mantenere il flusso entrante.
	- Se si tratta di sbarra che scorre senza attrito in guida metallica verticale vale
		- Se sbarra verso il basso, **verso della corrente antiorario**
		- Se sbarra verso l'alto, **verso della corrente orario**