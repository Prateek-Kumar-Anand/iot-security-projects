# 🐍 Python Coding — Data Handling, Functions & Web Scraping

A learning-focused collection of Python scripts covering some of the most practical day-to-day skills in data work: cleaning messy data, handling missing values with **pandas**, writing reusable **functions**, and pulling content from the web with **BeautifulSoup**. 📊🧹🌐

---

## 📦 About This Repository

This repo is a hands-on practice log built while learning core Python and data-handling concepts. Each script is small, focused, and meant to demonstrate **one concept at a time** — perfect for revisiting fundamentals or as a quick reference.

### Topics Covered
- 🧹 **Data Handling** — cleaning DataFrames, handling missing values (`dropna`, `fillna`), basic DataFrame manipulation
- 🔁 **Functions** — loops, conditionals, user input handling, simple interactive programs
- 🌐 **Web Scraping** — fetching and parsing HTML pages with `requests` + `BeautifulSoup`
- 📄 **CSV / JSON / PDF** *(work in progress)* — reading and processing structured data files

---

## 🗂️ Repository Structure

```
Python-coding-Missing_Data_Handeling/
├── 📁 data-handling/   → pandas scripts for DataFrames & missing-value handling
└── 📁 Functions/        → standalone scripts on functions, input/loops, and web scraping
```

Each sub-folder has its own `README.md` with details on every script inside.

---

## 🛠️ Requirements

- 🐍 Python 3.x
- 📦 Libraries used across the scripts:
  ```bash
  pip install pandas requests beautifulsoup4
  ```

---

## ▶️ Running the Scripts

1. Navigate into the relevant folder (`data-handling` or `Functions`).
2. Run any script directly:
   ```bash
   python "script_name.py"
   ```
3. For scripts that read a CSV (like `unclean.csv`), make sure the file stays in the **same folder** as the script — paths are relative.

---

## 📌 Notes

- ✏️ These scripts are written as **learning exercises**, so some include intentionally messy/realistic data (e.g. `unclean.csv` has encoding issues, duplicate columns, and missing values — great for practicing data cleaning!).
- 🌱 This is an evolving repo — CSV/JSON/PDF handling sections are planned additions.
- 💬 Filenames and code may include small typos (e.g. "manupulation", "Usuing") kept as-is from the original learning notes.

---

⭐ A growing record of "learn by doing" — explore the folders, run the scripts, and tweak them to see what changes!
