stocks = {"AAPL": 180,"TSLA": 250,"MSFT": 320,"GOOGL": 140,"KSFL": 350}
total = 0
portfolio = {}

print("Stock Portfolio Tracker")

while True:
    name = input("Enter stock name (or 'done'): ").upper()
    if name == "DONE":
        break
    if name not in stocks:
        print("Stock not found.")
        continue
    qty = int(input("Enter quantity: "))
    value = stocks[name] * qty
    portfolio[name] = value
    total += value

print("\nInvestment Summary")
for stock, value in portfolio.items():
    print(stock, ":", value)
print("Total Investment:", total)

with open("portfolio.txt", "w") as file:
    for stock, value in portfolio.items():
        file.write(f"{stock} : {value}\n")
    file.write(f"Total Investment : {total}")

print("Portfolio saved to portfolio.txt")
