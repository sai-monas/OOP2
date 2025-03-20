## Objektinis programavimas 2025

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

### 3.2 Atvejis - duomenų skirstymo pagal 2-i kategorijas greičio matavimas std::vector, std::list ir std::deque konteineriuose

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

### Visi duomenys: https://docs.google.com/spreadsheets/d/1-jWgfcVoi0Piz3YIMO9YADxN77jUyhKHUNEyebXa848/edit?usp=sharing
