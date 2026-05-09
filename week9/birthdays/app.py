from flask import Flask, render_template, request, redirect

app = Flask(__name__)

birthdays = []

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form.get("name")
        day = request.form.get("day")
        month = request.form.get("month")

        birthdays.append({"name": name, "day": day, "month": month})

        return redirect("/")

    return render_template("index.html", birthdays=birthdays)

if __name__ == "__main__":
    app.run(debug=True)
