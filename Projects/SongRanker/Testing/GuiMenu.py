import os
from pathlib import Path
import tkinter as tk
import random
from PIL import Image, ImageTk

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
                "width": 20,
                "wraplength": 110
            }

        self.label_properties = \
            {
                "bg": "light goldenrod",
                "height": 3,
                "width": 20,
                "wraplength": 110
            }

    def GetTwoRandomSongs(self):
        """
        Randomly selects two songs for the user to compare.

        Returned Values:
            left_song_data -- Data for the first song chosen.
            right_song_data -- Data for the second song chosen.

            Both left_song_data and right_song_data are structs consisting of the following fields of data:
                song_name -- The name of the song.
                album -- The album the song comes from.
                artist -- The artist that performs the song.
                elo -- The ELO score of the song, used for ranking songs.
        """
        # Determine two songs to compare based on line number
        left_song_pos = random.randrange(0, len(self.songs.list_of_lines) - 1, 1)
        right_song_pos = random.randrange(0, len(self.songs.list_of_lines) - 1, 1)

        # Ensures two distinct numbers
        while right_song_pos == left_song_pos:
            right_song_pos = random.randrange(0, len(self.songs.list_of_lines) - 1, 1)

        # Parse data for the two songs
        left_song_data = self.songs.list_of_lines[left_song_pos].split('~')
        right_song_data = self.songs.list_of_lines[right_song_pos].split('~')
        both_songs = [left_song_data, right_song_data]

        return both_songs

    def SelectLeftSong(self):
        print("Chose left song")

    def SelectRightSong(self):
        print("Chose right song")

    def RankSongs(self):
        menu = tk.Toplevel()
        menu.geometry("500x500")

        both_songs = self.GetTwoRandomSongs()

        # TODO: research how to rebuild window

        header_frame = tk.Frame(menu, bg="light blue", width=500, height=100)
        header_frame.place(x=0, y=0)

        left_song_frame = tk.Frame(menu, bg="pale green", width=250, height=300)
        left_song_frame.place(x=0, y=100)

        left_canvas = tk.Canvas(left_song_frame, width=150, height=150)

        left_image = os.path.splitext(both_songs[0][1])[0]
        left_path = Path(os.getcwd()).parent / "ResourceFiles\\Album Covers" / (left_image + ".jpg")
        left_img = ImageTk.PhotoImage(Image.open(left_path).resize((150, 150)))

        left_canvas.create_image(0, 0, image=left_img, anchor="nw")
        left_canvas.place(x=0, y=0)

        left_song_info = \
            tk.Label(left_song_frame, **self.label_properties, text=both_songs[0][2] + ": " + both_songs[0][1])
        left_song_info.place(x=0, y=194)

        left_song_button = \
            tk.Button(left_song_frame, **self.button_properties, text=both_songs[0][0], command=self.SelectLeftSong)
        left_song_button.place(x=0, y=244)

        right_song_frame = tk.Frame(menu, bg="pale green", width=250, height=300)
        right_song_frame.place(x=250, y=100)

        right_canvas = tk.Canvas(right_song_frame, width=150, height=150)

        right_image = os.path.splitext(both_songs[1][1])[0]
        right_path = Path(os.getcwd()).parent / "ResourceFiles\\Album Covers" / (right_image + ".jpg")
        right_img = ImageTk.PhotoImage(Image.open(right_path).resize((150, 150)))

        right_canvas.create_image(0, 0, image=right_img, anchor="nw")
        right_canvas.place(x=95, y=0)

        right_song_info = \
            tk.Label(right_song_frame, **self.label_properties, text=both_songs[1][2] + ": " + both_songs[1][1])
        right_song_info.place(x=105, y=194)

        right_song_button = \
            tk.Button(right_song_frame, **self.button_properties, text=both_songs[1][0], command=self.SelectRightSong)
        right_song_button.place(x=105, y=244)

        footer_frame = tk.Frame(menu, bg="light blue", width=500, height=100)
        footer_frame.place(x=0, y=400)

        exit_button = tk.Button(footer_frame, **self.button_properties, text="Exit", command=menu.destroy)
        exit_button.place(x=351, y=45)

        menu.mainloop()

    def BuildButtons(self, gui):
        rank_songs = tk.Button(gui, **self.button_properties, text="Rank Songs", command=self.RankSongs)
        change_k_value = tk.Button(gui, **self.button_properties, text="Change K Value", )
        display_top_songs = tk.Button(gui, **self.button_properties, text="Display Top Songs", )
        view_song = tk.Button(gui, **self.button_properties, text="View Song", )
        reset_song = tk.Button(gui, **self.button_properties, text="Reset Songs", )
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
