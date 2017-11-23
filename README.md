# Eagle Sensors Project 

## Volante

### Descrizione del Repository 

In questa cartella sono contenuti tutti i file per far girare l'interfaccia del volante. 
Questa funziona in due modalità:

* **Desktop**: compilata per PC Desktop (architettura x86), serve per il debug, per il testing e per la prototipazione veloce, anche quando non dovesse essere disponibile il Raspberry. 
* **Embedded**: cross-compilata per Raspberry Pi 2/Zero W, viene compilata sul PC Host (il desktop) e poi mandata al Raspberry via SSH dove viene lanciato l'eseguibile (per piattaforma ARM). 

**ATTENZIONE**: L'eseguibile compilato per ARM ***non funziona*** su macchina Intel/AMD x86, è necessario inviarla al sistema Embedded e quindi eseguirla in quel contesto.

### Descrizione Tecnica 

### Usage Simulatore Sensori

Assicurarsi di avere entrambe le cartelle SimulatoreSensori e Volante nella stessa directory. Sia SimulatoreSensori che Volante devono contenere una cartella build.
Entrare nella cartella SimulatoreSensori ed eseguire `deploy.sh`
```sh
$ cd SimulatoreSensori
$ ./deploy.sh
```
Dopo la compilazione si aprirá l'interfaccia del simulatore sensori. Per impostare i valori dei sensori utilizzare la parte sinistra dell'applicazione. Per navigare l'interfaccia del volante utilizzare i bottoni che si trovano nella parte destra dell'applicazione.

## Muretto
