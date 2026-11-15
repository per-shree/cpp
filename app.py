
from flask import Flask, Response, abort

app = Flask(__name__)

PRACTICALS = {
    1: "Exp1_Search.cpp",
    2: "Exp2_Sort.cpp",
    3: "Exp3_Stack.cpp",
    4: "Exp4_Queue.cpp",
    5: "Exp5_SLL.cpp",
    6: "Exp6_DLL.cpp",
    7: "Exp7_Hash.cpp",
    8: "Exp8_Chaining.cpp",
    9: "Exp9_BST.cpp",
    10: "Exp10_Graph.cpp"
}


@app.route("/")
def home():
    return """
    <h1>CPP DSCloud</h1>
    <p>C++ Practical Code Repository</p>
    <p>Access practicals using /t/1 to /t/10</p>
    <a href="/t/0">View Practical Index</a>
    """


@app.route("/health")
def health():
    return {"status": "OK"}


@app.route("/t/0")
def index():
    result = "CPP DSCloud - Practical Index\n\n"

    for number, filename in PRACTICALS.items():
        result += f"{number}. {filename} - /t/{number}\n"

    return Response(result, mimetype="text/plain")


@app.route("/t/<int:number>")
def get_practical(number):

    filename = PRACTICALS.get(number)

    if filename is None:
        abort(404, description="Practical not found")

    try:
        with open(filename, "r", encoding="utf-8") as file:
            code = file.read()

        return Response(code, mimetype="text/plain")

    except FileNotFoundError:
        abort(404, description="Code file not found")
