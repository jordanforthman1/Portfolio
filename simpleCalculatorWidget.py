import tkinter as tk
from tkinter import messagebox

window = tk.Tk()
window.title('Calculator')

switch = tk.IntVar()
switch.set(0)

def clicked():
    #Error handling within entry fields
    if entry1.get().isdigit() == False or entry2.get().isdigit() == False:
        messagebox.showerror('Error!', 'Fields must contain numbers only!')
        if entry1.get().isdigit():
            entry2.focus_set()
        else:
            entry1.focus_set()

    if switch.get() == 3 and int(entry2.get()) == 0:
        messagebox.showerror('Error!', 'Cannot divide by 0!')
        

    #Execution
    else:
        if switch.get() == 0:
            messagebox.showinfo('Result', int(entry1.get()) + int(entry2.get()))
        if switch.get() == 1:
            messagebox.showinfo('Result', int(entry1.get()) - int(entry2.get()))
        if switch.get() == 2:
            messagebox.showinfo('Result', int(entry1.get()) * int(entry2.get()))
        if switch.get() == 3:
            messagebox.showinfo('Result', int(entry1.get()) / int(entry2.get()))

entry1 = tk.Entry(window, width=30)
entry2 = tk.Entry(window, width=30)
entry1.grid(row=3, column=1)
entry2.grid(row=3, column=3)

radio1 = tk.Radiobutton(window, text='+', variable=switch, value=0)
radio2 = tk.Radiobutton(window, text='-', variable=switch, value=1)
radio3 = tk.Radiobutton(window, text='*', variable=switch, value=2)
radio4 = tk.Radiobutton(window, text='/', variable=switch, value=3)
radio1.grid(row=1, column=2)
radio2.grid(row=2, column=2)
radio3.grid(row=4, column=2)
radio4.grid(row=5, column=2)

evaluate = tk.Button(window, text='Evaluate', command=clicked)
evaluate.grid(row=6, column=2)

tk.mainloop()
