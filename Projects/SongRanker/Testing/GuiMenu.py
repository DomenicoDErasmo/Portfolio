import os
import tkinter as tk
import random

from CustomModules import FileReader, SongFileReader, SongUpdater, MenuDisplay, SongComparison


class GuiMenu:

    def __init__(self):
        """
        Initializes the file readers used in the program.
        """

        # Gets our file paths components.
        project_path = os.path.dirname(os.path.dirname(__file__))
        song_file_path = "/ResourceFiles/BTS_Song_Data"
        settings_file_path = "/ResourceFiles/Settings"

        # Constructs the file paths.
        song_file = project_path + song_file_path
        settings_file = project_path + settings_file_path

        # Initializes the file readers based on the file paths provided.
        self.songs = SongFileReader.SongFileReader(song_file)
        self.settings = FileReader.FileReader(settings_file)

        # Initializes the song ranker
        self.songs.GetFileLines()
        self.song_arranger = SongUpdater.SongArranger(self.songs.list_of_lines)

        # Builds GUI button properties
        self.button_properties = \
            {
                "bg": "orchid1",
                "height": 3,
                "width": 20
            }

    def BuildButtons(self, gui):
        rank_songs = tk.Button(gui, **self.button_properties, text="Rank Songs", )
        change_k_value = tk.Button(gui, **self.button_properties, text="Change K Value", )
        display_top_songs = tk.Button(gui, **self.button_properties, text="Display Top Songs", )
        view_song = tk.Button(gui, **self.button_properties, text="View Song", )
        reset_song = tk.Button(gui, **self.button_properties, text="Reset Song", )
        exit_button = tk.Button(gui, **self.button_properties, text="Exit", command=exit)

        rank_songs.place(x=0, y=50)
        change_k_value.place(x=0, y=105)
        display_top_songs.place(x=0, y=160)
        view_song.place(x=200, y=50)
        reset_song.place(x=200, y=105)
        exit_button.place(x=200, y=160)

    # TODO: add functions to BuildButtons and to class, replace all command line prompts with GUIs
    def RunMenu(self):
        gui = tk.Tk()
        gui.geometry("350x300")
        gui.configure(bg="powder blue")
        self.BuildButtons(gui)
        gui.mainloop()
