using UnityEngine;
using System.Collections;

public class Enemy : MonoBehaviour
{
    public float MinSpeed;
    public float MaxSpeed;

    private float _currentSpeed;
    private float _x, _y, _z;

    void Start()
    {
        Spawn();
    }

    void Update()
    {
        var amountToMove = _currentSpeed * Time.deltaTime;

        transform.Translate(Vector3.down * amountToMove);

        if (transform.position.y <= -5f)
        {
            Spawn();
            Player.Missed++;
        }
    }

    public void Spawn()
    {
        _currentSpeed = Random.Range(MinSpeed, MaxSpeed);
        _x = Random.Range(-6.3f, 6.3f);
        _y = 7f;
        _z = 6f;

        transform.position = new Vector3(_x, _y, _z);
    }
}
