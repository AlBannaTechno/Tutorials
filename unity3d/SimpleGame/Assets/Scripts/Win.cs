using UnityEngine;
using System.Collections;

public class Win : MonoBehaviour
{
    public Texture BackgroundTexture;

    private const int ButtonWidth = 200;
    private const int ButtonHeight = 50;

    void OnGUI()
    {
        GUI.DrawTexture(new Rect(0, 0, Screen.width, Screen.height), BackgroundTexture);
        GUI.Label(new Rect(20, 200, 250, 100), "You win!\nPress any key to play again");

        if (Input.anyKeyDown)
        {
            Player.Score = 0;
            Player.Lives = 3;
            Player.Missed = 0;

            Application.LoadLevel(1);
        }
    }
}
