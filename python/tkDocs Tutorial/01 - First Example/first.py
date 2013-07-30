import tkinter as tk
from tkinter import ttk

def calculate(*args):
    try:
        value = float(feet.get())
        meters.set((0.3048 * value * 10000.0 + 0.5) / 10000.0)

    except:
        pass

root = tk.Tk()
root.title("Feet to Meters")

ui_main_frame = ttk.Frame(root, padding="3 3 12 12")
ui_main_frame.grid(column=0, row=0, sticky=(tk.N, tk.W, tk.E, tk.S))
ui_main_frame.columnconfigure(0, weight=1)
ui_main_frame.rowconfigure(0, weight=1)

feet = tk.StringVar()
meters = tk.StringVar()

ui_feet_entry = ttk.Entry(ui_main_frame, width=7, textvariable=feet)
ui_feet_entry.grid(column=2, row=1, sticky=(tk.W, tk.E))

ttk.Label(ui_main_frame, textvariable=meters).grid(column=2, row=2, sticky=(tk.W, tk.E))
ttk.Button(ui_main_frame, text="Calculate", command=calculate).grid(column=3, row=3, sticky=tk.W)

ttk.Label(ui_main_frame, text="feet").grid(column=3, row=1, sticky=tk.W)
ttk.Label(ui_main_frame, text="is equivalent to").grid(column=1, row=2, sticky=tk.E)
ttk.Label(ui_main_frame, text="meters").grid(column=3, row=2, sticky=tk.W)

for child in ui_main_frame.winfo_children():
    child.grid_configure(padx=5, pady=5)

ui_feet_entry.focus()
root.bind('<Return>', calculate)

root.mainloop()
