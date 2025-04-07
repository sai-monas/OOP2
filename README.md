## Objektinis programavimas 2025

## "Releases" apžvalga

### v.pradine - pre-release
- Programa nuskaito vartotojų įvedamus studentų duomenis (vardą, pavardę, namų darbų ir egzamino pažymius), bei išveda studentus ir, pasirinktinai, jų pažymių medianas ar vidurkius į terminalą.
- Naudojami std::vector tipo konteineriai.

### v0.1
- Yra galimybė studentų gautus pažymius generuoti atsitiktinai.
- 2 programos versijos - code_testas.cpp naudoja std::vector tipo konteinerius, o code_array - array tipo konteinerius.

### v0.2
- Yra galimybė studentų duomenis nuskaityti iš vartotojų pateikiamų failų, ir pateikti terminale išrūšiuotus pagal vartotojo pasirinkimą
- Naudojami std::vector tipo konteineriai

### v0.3
- Sukurtas naujas functions.cpp failas talpinantis funkcijas naudojamas pagrindiniame faile.

### v0.4
- Vartotojai turi galimybę atsitiktinai generuoti naujus failus su studentų duomenimis, ir juos apdoroti naudojant programą.
- Studentai dabar rūšiuojami į 2 atskirus failus pagal jų pažymių vidurkį.

### v1.0
- Optimizuotas studentų skirstymas į 2 atskirus konteinerius.
- Naudojami std::vector, std::list, std::deque tipo konteineriai (skirtinguose .cpp failuose).

## Naudojimosi instrukcijos
- Paleidę programą galėsite pasirinkti tarp 4 pagrindinių duomenų įvesties būdų - rankinio, pusiau rankinio, pilnos atsitiktinės generacijos, ar darbo su failu.
- Pasirinkus 1-ąjį būdą, visus studentų duomenis turėsite įvesti ranka. Norint nutraukti pažymių įvestį reikia įrašyti 0, o baigus studentų įvestį - X.
- Pasirinkus 2-ąjį būdą, programoje turėsite įvesti norimą skaičių sugeneruotų pažymių. Studentų įvesties baigčiai vėl gi turėsite įvesti X.
- Pasirinkus 3-iąjį būdą, programoje turėsite įvesti norimą skaičių sugeneruotų studentų ir jų pažymių.
- Pasirinkus 4-ąjį būdą galėsite arba generuoti failą su atsitiktinais duomenimis, arba pateikti savo.

## Testavimo rezultatai
### 1.1 Atvejis - failų generavimo greičio matavimas didinant tik studentų (eilučių) kiekį

**Nuotraukos iš pirmo testavimo**

*1 000 studentų:*

![image](https://github.com/user-attachments/assets/1b7f6f3e-f13d-4cad-a5cb-dbb26d782d3e)

*10 000 studentų:*

![image](https://github.com/user-attachments/assets/adaaada4-0cf3-49d1-bffa-cd2d4658ac77)

*100 000 studentų:*

![image](https://github.com/user-attachments/assets/8b36547b-b6bd-4bf7-a2f6-e5579f4588a2)

*1 000 000 studentų:*

![image](https://github.com/user-attachments/assets/2f12fe07-f08c-4543-bc83-bedf88a0a715)

*10 000 000 studentų:*

![image](https://github.com/user-attachments/assets/7b70710d-514c-4ddc-9b6e-20f4ddd90528)

| Studentų skaičius | Namų darbų įvertinimų skaičius | Greičio vidurkis (s) |
| :------------- | :------------- | :------------- |
| 1000 | 10 | 0.0122512 |
| 10000 | 10 | 0.0404024 |
| 100000 | 10 | 0.2910102 |
| 1000000 | 10 | 2.816906 |
| 10000000 | 10 | 30.96842 |

### 1.2 Atvejis - failų generavimo greičio matavimas didinant tik įvertinimų kiekį

*15 įvertinimų:*

![image](https://github.com/user-attachments/assets/80d46a7a-aba3-420d-a25b-a116debb0d59)

*20 įvertinimų:*

![image](https://github.com/user-attachments/assets/f2c38183-aa0f-40f4-84fd-f6b82cc3f334)

*25 įvertinimai:*

![image](https://github.com/user-attachments/assets/e20c5fb0-0957-43cf-a1dc-f97b43649be3)

*30 įvertinimų:*

![image](https://github.com/user-attachments/assets/b0978b60-b8c9-4b15-9b3b-4148ebeba1fc)

*35 įvertinimai:*

![image](https://github.com/user-attachments/assets/e2095aac-e464-4034-ae49-20e43bea67da)

| Studentų skaičius | Namų darbų įvertinimų skaičius | Greitis (s) |
| :------------- | :------------- | :------------- |
| 1000000 | 15 | 5.77697 |
| 1000000 | 20 | 3.57288 |
| 1000000 | 25 | 3.92783 |
| 1000000 | 30 | 4.31643 |
| 1000000 | 35 | 8.11556 |

### 2.1 Atvejis - darbas su egzistuojančiais failais (duomenų apdorojimo greičio testavimas)

**Nuotraukos iš pirmo testavimo**

*1 000 studentų:*

![image](https://github.com/user-attachments/assets/2b825d08-715c-48a9-864f-bee1a0e1088b)

*10 000 studentų:*

![image](https://github.com/user-attachments/assets/064872cb-9577-4d78-afb4-2b8cb3ef55ae)

*100 000 studentų:*

![image](https://github.com/user-attachments/assets/693b1bea-2e2c-4b20-9649-f8d3dc4b0e9e)

*1 000 000 studentų:*

![image](https://github.com/user-attachments/assets/01a1ec77-db54-4906-aa95-92f5bf73b2a4)

*10 000 000 studentų:*

![image](https://github.com/user-attachments/assets/eeef9e09-46d0-4300-b9d6-c159b2b35181)

| Studentų skaičius | Namų darbų įvertinimų skaičius | Nuskaitymo greičio vidurkis (s) | Rūšiavimo greičio vidurkis (s) | Kūrimo greičio vidurkis (s) |
| :------------- | :------------- | :------------- | :------------- | :------------- |
| 1000 | 10 | 0.0053923333333333 | 0.000778 | 0.0492713333333333 |
| 10000 | 10 | 0.032917 | 0.003502 | 0.042725 |
| 100000 | 10 | 0.2685646666666667 | 0.034273 | 0.3486626666666667 |
| 1000000 | 10 | 2.619323333333333 | 0.4498686666666667 | 3.216073333333333 |
| 10000000 | 10 | 78.3122 | 4.86689 | 112.256 |

### 3.1 Atvejis - duomenų (iš failų) nuskaitymo greičio matavimas naudojant std::vector, std::list ir std:: deque konteinerius

| Konteinerio tipas | Studentų skaičius | Namų darbų įvertinimų skaičius | Greičio vidurkis (s) |
| :------------- | :------------- | :------------- | :------------- |
| `std::vector` | 1000 | 10 | 0.005746 |
| `std::list` | 1000 | 10 | 0.0065286666666667 |
| `std::deque` | 1000 | 10 | 0.0058723333333333 |
| `std::vector` | 10000 | 10 | 0.030343 |
| `std::list` | 10000 | 10 | 0.0307806666666667 |
| `std::deque` | 10000 | 10 | 0.0292293333333333 |
| `std::vector` | 100000 | 10 | 0.2678933333333333 |
| `std::list` | 100000 | 10 | 0.2847606666666667 |
| `std::deque` | 100000 | 10 | 0.272234 |
| `std::vector` | 1000000 | 10 | 2.606556666666667 |
| `std::list` | 1000000 | 10 | 2.84913 |
| `std::deque` | 1000000 | 10 | 2.757913333333333 |
| `std::vector` | 10000000 | 10 | 26.72416666666667 |
| `std::list` | 10000000 | 10 | 28.15683333333333 |
| `std::deque` | 10000000 | 10 | 27.24956666666667 |

- Naudojant std::vector tipo konteinerius duomenys buvo nuskaityti greičiausiai
- Naudojant std::list tipo konteinerius duomenys buvo nuskaityti lėčiausiai
- Duomenų nuskaitymo greičio vidurkio skirtumas tarp šių konteinerių buvo ~1.433 sekundės

### 3.2 Atvejis - duomenų rūšiavimo greičio matavimas std::vector, std::list ir std::deque konteineriuose

| Konteinerio tipas | Studentų skaičius | Namų darbų įvertinimų skaičius | Greičio vidurkis (s) |
| :------------- | :------------- | :------------- | :------------- |
| `std::vector` | 1000 | 10 | 0.000694 |
| `std::list` | 1000 | 10 | 0.000313 |
| `std::deque` | 1000 | 10 | 0.00086533333333333318886 |
| `std::vector` | 10000 | 10 | 0.0136056666666667 |
| `std::list` | 10000 | 10 | 0.001797 |
| `std::deque` | 10000 | 10 | 0.0061756666666667 |
| `std::vector` | 100000 | 10 | 0.0755466666666667 |
| `std::list` | 100000 | 10 | 0.025837 |
| `std::deque` | 100000 | 10 | 0.08139 |
| `std::vector` | 1000000 | 10 | 0.9694076666666667 |
| `std::list` | 1000000 | 10 | 0.5147113333333333 |
| `std::deque` | 1000000 | 10 | 1.05566 |
| `std::vector` | 10000000 | 10 | 12.11376666666667 |
| `std::list` | 10000000 | 10 | 9.23503 |
| `std::deque` | 10000000 | 10 | 13.1431 |

- Naudojant std::list tipo konteinerius duomenys buvo išrūšiuoti greičiausiai
- Naudojant std::deque tipo konteinerius duomenys buvo išrūšiuoti lėčiausiai
- Duomenų rūšiavimo greičio vidurkio skirtumas tarp šių konteinerių buvo ~3.908 sekundės

### 3.3 Atvejis - duomenų skirstymo pagal 2-i kategorijas greičio matavimas std::vector, std::list ir std::deque konteineriuose

| Konteinerio tipas | Studentų skaičius | Namų darbų įvertinimų skaičius | Greičio vidurkis (s) |
| :------------- | :------------- | :------------- | :------------- |
| `std::vector` | 1000 | 10 | 0.000445 |
| `std::list` | 1000 | 10 | 0.00047 |
| `std::deque` | 1000 | 10 | 0.000391 |
| `std::vector` | 10000 | 10 | 0.0115656666666667 |
| `std::list` | 10000 | 10 | 0.002505 |
| `std::deque` | 10000 | 10 | 0.0021743333333333 |
| `std::vector` | 100000 | 10 | 0.0278643333333333 |
| `std::list` | 100000 | 10 | 0.0293103333333333 |
| `std::deque` | 100000 | 10 | 0.0232026666666667 |
| `std::vector` | 1000000 | 10 | 0.3366546666666667 |
| `std::list` | 1000000 | 10 | 0.4141273333333333 |
| `std::deque` | 1000000 | 10 | 0.2763606666666667 |
| `std::vector` | 10000000 | 10 | 3.541686666666667 |
| `std::list` | 10000000 | 10 | 4.11246 |
| `std::deque` | 10000000 | 10 | 2.966826666666667 |

- Naudojant std::deque tipo konteinerius duomenys buvo išskirstyti greičiausiai
- Naudojant std::list tipo konteinerius duomenys buvo išskirstyti lėčiausiai
- Duomenų skirstymo greičio vidurkio skirtumas tarp šių konteinerių buvo ~1.146 sekundės

| Vieta | Konteinerio tipas | Visų užduočių greičio vidurkis (s) |
| :------------- | :------------- | :------------- |
| :1st_place_medal: | `std::list` | 41.50432333333333 |
| :2nd_place_medal: | `std::vector` | 42.37962000000001 |
| :3rd_place_medal: | `std::deque` | 43.35949333333334 |

### 4.1 Atvejis - duomenų skirstymo greičio matavimas panaudojant tik vieną naują std::vector, std::list ar std::deque tipo konteinerį

| Konteinerio tipas | Studentų skaičius | Namų darbų įvertinimų skaičius | Greičio vidurkis (s) |
| :------------- | :------------- | :------------- | :------------- |
| `std::vector` | 1000 | 10 | 0.000316 |
| `std::list` | 1000 | 10 | 0.0002256 |
| `std::deque` | 1000 | 10 | 0.000156 |
| `std::vector` | 10000 | 10 | 0.00173 |
| `std::list` | 10000 | 10 | 0.0014183 |
| `std::deque` | 10000 | 10 | 0.00118 |
| `std::vector` | 100000 | 10 | 0.017883 |
| `std::list` | 100000 | 10 | 0.0174226 |
| `std::deque` | 100000 | 10 | 0.013152 |
| `std::vector` | 1000000 | 10 | 0.2571606 |
| `std::list` | 1000000 | 10 | 0.267454 |
| `std::deque` | 1000000 | 10 | 0.2051123 |
| `std::vector` | 10000000 | 10 | 2.773783 |
| `std::list` | 10000000 | 10 | 2.892786 |
| `std::deque` | 10000000 | 10 | 2.32154 |

- Kaip ir 3.3, matoma, kad duomenų skirstymas greičiausiai įvykdomas naudojant std::deque versiją
- 4.1 implementuotas skirstymas funkcionalus tik su duomenimis iš anksto surūšiuotais pagal vidurkį

### 4.2 Atvejis - duomenų skirstymo greičio matavimas panaudojant tik vieną naują std::vector konteinerį bei pritaikant skirtingiems rūšiavimams

| Studentų skaičius | Namų darbų įvertinimų skaičius | Greičio vidurkis (s) |
| :------------- | :------------- | :------------- |
| 1000 | 10 | 0.000436 |
| 10000 | 10 | 0.0023816 |
| 100000 | 10 | 0.0227656 |
| 1000000 | 10 | 0.2663453 |
| 10000000 | 10 | 3.199913333333333 |

- Šis atvejis yra greitesnis lyginant su 3.3 ir 4.1 versijomis

### 5.1 Atvejis - darbas su egzistuojančiais failais (duomenų apdorojimo greičio testavimas) naudojant class tipo talpyklas studentams

| Studentų skaičius | Namų darbų įvertinimų skaičius | Nuskaitymo greičio vidurkis (s) | Rūšiavimo greičio vidurkis (s) | Kūrimo greičio vidurkis (s) |
| :------------- | :------------- | :------------- | :------------- | :------------- |
| 100000 | 10 | 0.2125666666666667 | 0.225403 | 0.032192 |
| 1000000 | 10 | 2.086196666666667 | 2.817283333333333 | 0.3373903333333333 |

## Testavimui naudotos sistemos specifikacijos

- CPU - Intel(R) Core(TM) i7-14700HX
- RAM - 16 GB
- SSD (NVMe)

### Visi duomenys: https://docs.google.com/spreadsheets/d/1-jWgfcVoi0Piz3YIMO9YADxN77jUyhKHUNEyebXa848/edit?usp=sharing
