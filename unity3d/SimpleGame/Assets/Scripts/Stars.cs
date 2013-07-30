using UnityEngine;
using System.Collections;

public class Stars : MonoBehaviour
{
    public float Speed;

    void Update()
    {
        var amountToMove = Speed * Time.deltaTime;
        transform.Translate(Vector3.down * amountToMove, Space.World);

        if (transform.position.y <= -11.6f)
            transform.position = new Vector3(transform.position.x, 16, transform.position.z);
    }
}
