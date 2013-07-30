using UnityEngine;
using System.Collections;

public class MainMenu : MonoBehaviour
{
    public Texture BackgroundTexture;

    private readonly string _instructionText = string.Format(
        "*Instructions*\n" +
        "Press A and D keys to move\n" +
        "Press SpaceBar to shoot\n\n" +
        "Press any key to start");

    private const int ButtonWidth = 200;
    private const int ButtonHeight = 50;

    void OnGUI()
    {
        GUI.DrawTexture(new Rect(0, 0, Screen.width, Screen.height), BackgroundTexture);

        GUI.Label(new Rect(20, 20, 250, 250), _instructionText);
        
        if (Input.anyKeyDown)
            Application.LoadLevel(1);
    }
}
