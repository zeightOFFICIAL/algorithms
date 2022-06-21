# String-searching algorithms
Comparison of string-searching algorithms

* Version 1.2

In computer science, string-searching algorithms, sometimes called string-matching algorithms, are an important class of string algorithms that try to find a place where one or several strings (also called patterns) are found within a larger string or text. A basic example of string searching is when the pattern and the searched text are arrays of elements of an alphabet.

Currently available algorithms:

* <b><em>Boyer-Moore</em></b> is an efficient string-searching algorithm that is the standard benchmark for practical string-search literature. It was developed by Robert S. Boyer and J Strother Moore in 1977.
* <b><em>Rabin-Karp</em></b> is a string-searching algorithm created by Richard M. Karp and Michael O. Rabin (1987) that uses hashing to find an exact match of a pattern string in a text. It uses a rolling hash to quickly filter out positions of the text that cannot match the pattern, and then checks for a match at the remaining positions.
* <b><em>Naïve algorithm</em></b> is a simple string-searching algorithm. It checks for all character of the main string to the pattern. Naive algorithm is exact string matching.
* <b><em>Bitap (Shift-OR)</em></b>, distinguishes itself from other well-known string searching algorithms in its natural mapping onto simple bitwise operations.

| Algorithm | Type | Matching time |
| :---:                 | :---:               | :---:  |
| Naive                 | Simple indexing, checks pattern and text one symbol at a time     | $$O(nm)$$ in best: $$ O(2m) $$  |
| Boyer-Moore (1977)    | Bad char heuristics, advanced naive algorithm| $$O(mn)$$ in best: $$O(m/n)$$  |
| Rabin-Karp (1987)     | Hashing, compare hash of pattern with hash of text             | $$O(mn)$$  |
| Bitap (1964) Shift-OR | Uses features of circular bit shift and linearizability of bitwise OR and SHIFT | $$O(m*(n/32))$$ |

---
## Test results
The power of alphabet is 64 symbols (upper, lower-case latin, numbers). Length is adjustible. Searched pattern is 'ab'.

| Length of string (n)| Boyer-Moore (s) | Rabin-Karp (s) | Naive algorithm (s)| Bitap (s)|
|:---:|:---:|:---:|:---:|:---:|
|10000|0.00044528|0.00084279|0.00048676|0.00040674|
|20000|0.00141864|0.00275334|0.00147991|0.00120131|
|30000|0.00303507|0.00553472|0.00331678|0.00241929|
|40000|0.00482498|0.00902084|0.00532098|0.00395522|
|50000|0.00736731|0.01326877|0.00782397|0.00575456|
|60000|0.00994308|0.01854943|0.01089774|0.00792414|
|70000|0.01299647|0.02463621|0.01438224|0.01052214|
|80000|0.01656912|0.03201902|0.01854766|0.01349326|
|90000|0.02062369|0.04032529|0.02357771|0.01688248|
|100000|0.02542911|0.05000123|0.02901575|0.02081275|
|110000|0.03039305|0.05968939|0.03462523|0.02495525|
|120000|0.03595365|0.07053444|0.04084691|0.02946999|
|130000|0.04148954|0.08172116|0.04725585|0.03422117|
|140000|0.04755494|0.09381177|0.05420432|0.03929559|
|150000|0.05407753|0.10685734|0.06156331|0.04481751|
|160000|0.06101044|0.12072141|0.06958987|0.05070344|
|170000|0.06863086|0.13615419|0.07837339|0.05710891|
|180000|0.08002702|0.15870904|0.09164894|0.06648731|
|190000|0.09041438|0.17775072|0.10286038|0.07454089|
|200000|0.10054877|0.19922633|0.11457127|0.08358362|

The power of alphabet is 64 symbols (upper, lower-case latin, numbers). Length is adjustible. Searched pattern is 'abcde'.
| Length of string (n)| Boyer-Moore (s) | Rabin-Karp (s) | Naive algorithm (s)| Bitap (s)|
|:---:|:---:|:---:|:---:|:---:|
|10000|0.00020475|0.00113591|0.00052572|0.00042751|
|20000|0.00065153|0.00326415|0.00177857|0.00152537|
|30000|0.00126309|0.00636527|0.00344656|0.00271623|
|40000|0.00199932|0.00993264|0.00556913|0.00423167|
|50000|0.00292932|0.01512533|0.00818496|0.00612468|
|60000|0.00402271|0.02064715|0.01151007|0.00831355|
|70000|0.00524635|0.02684656|0.01495906|0.01085068|
|80000|0.00665828|0.03382534|0.01890513|0.01365259|
|90000|0.00822741|0.04200056|0.02364165|0.01699188|
|100000|0.01020595|0.05184241|0.02904387|0.02138226|
|110000|0.01234068|0.06209608|0.03470081|0.02609057|
|120000|0.01442195|0.07261883|0.04043778|0.03051981|
|130000|0.016800173|0.08474993|0.0469648|0.03529383|
|140000|0.019287023|0.09821835|0.0540890|0.04058862|
|150000|0.022095214|0.11198925|0.0620162|0.04613697|
|160000|0.024858735|0.12621351|0.0701146|0.05188975|
|170000|0.027734693|0.14067752|0.0780166|0.05771457|
|180000|0.030709213|0.15564077|0.0863551|0.06386371|
|190000|0.033953694|0.17204238|0.0954919|0.07052567|
|200000|0.037264933|0.18891995|0.1046863|0.07729333|
